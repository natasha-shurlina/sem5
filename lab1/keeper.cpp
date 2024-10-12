#include "keeper.h"

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {cout << "Keeper: Конструктор без параметров\n";}

Keeper::Keeper(Node* h, Node* t, int c) : head(h), tail(t), count(c) {cout << "Keeper: Конструктор с параметрами\n";}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Keeper: Конструктор копирования\n";
}

Keeper::~Keeper() {
    cout << "Keeper: Деструктор\n";
    delete_all();
}

void Keeper::delete_head() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
        if (count == 0) {
            tail = nullptr;
        }
    }
}

void Keeper::delete_all() {
    while (head != 0)
        delete_head();
    
}

void Keeper::print_keeper() {
    Node* temp = head;
    if (count == 0) {
        cout << "Данных нет" << endl;
        return;
    }
    int i = 0;
    while (temp != 0) {
        cout << i + 1 <<" - ";
        if (temp->data) {
            temp->data->display(); 
        } else {
            cout << "Данных нет";
        }
        cout << " " << endl;;
        temp = temp->next;
        i++;
    }
}

int Keeper::get_count() {
    return count;
}

void Keeper::add(Ship* temp) {
    Node* newElement = new Node;
    newElement->data = temp; 
    newElement->next = nullptr;
    if (head == nullptr) {
        head = tail = newElement;
    } else {
        tail->next = newElement;
        tail = newElement;
    }
    count++;
}

Keeper& Keeper::delete_Node(int n) {
    if (n < 1 || n > count) {
        cout << "Неправильный индекс элемента" << endl;
        return *this;
    }
    if (n == 1) {
        this->delete_head(); 
        return *this;
    }
    Node* temp = head;
    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail) {
        tail = temp;
    }
    delete toDelete->data;
    delete toDelete;
    count--;
    cout << "Объект удален.\n";
    return *this;
}

Keeper& Keeper::edit_Node(int n) {
    if (n < 1 || n > count) {
        cout << "Неправильный индекс элемента" << endl;
        return *this;
    }
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }
    if (temp->data) {
        temp->data->change_info(); 
    } else {
        cout << "Данных нет" << endl;
    }
    cout << "Данные исправлены.\n";
    return *this;
}

void Keeper::save(const string& filename) {
    ofstream out(filename);
    Node* current = head;
    while (current != nullptr) {
        current->data->save(out);
        current = current->next;
    }
    out.close();
    cout << "Файлы сохранены.\n";
}

void Keeper::load(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Ошибка открытия файла для загрузки!" << endl;
        return;
    }
    string marker;
    while (getline(in, marker)) {
        if (!marker.empty() && marker.back() == '\r') {
            marker.pop_back();
        }
        Ship* temp = nullptr;
        if (marker == "Speedboat") {
            temp = new Speedboat();
        } else if (marker == "Sailboat") {
            temp = new Sailboat();
        } else if (marker == "Submarine") {
            temp = new Submarine();
        } else {
            cerr << "Неизвестный тип объекта: " << marker << endl;
            continue; 
        }
        if (temp) {
            temp->load(in);
            cout << "Объект добавлен в контейнер" << endl;
            this->add(temp);
        }
    }
    in.close();
}

Keeper& Keeper::operator!() {
    if (count <= 1) {
        cout << "Мало элементов для изменения порядка." << endl;
        return *this;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    tail = head;

    while (current != nullptr) {
        next = current->next; 
        current->next = prev; 
        prev = current;      
        current = next;
    }

    head = prev; 
    cout << "Элементы контейнера поменяны местами." << endl;
    
    return *this;
}

Keeper& Keeper::operator*() {
    this->delete_head(); 
    cout << "Первый элемент удален из контейнера оператором '*'" << endl;
    return *this;
}