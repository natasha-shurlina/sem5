#include "keeper.h"
// Конструктор без параметров
Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {cout << "Keeper: Конструктор без параметров\n";}
// Конструктор с параметрами
Keeper::Keeper(Node* h, Node* t, int c) : head(h), tail(t), count(c) {cout << "Keeper: Конструктор с параметрами\n";}
// Конструктор копирования
Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Keeper: Конструктор копирования\n";
}
// Деструктор
Keeper::~Keeper() {
    cout << "Keeper: Деструктор\n";
    delete_all();
}
// Удаление первого элемента из списка
void Keeper::delete_head() {
    if (head) {  // Проверяем, есть ли элементы
        Node* temp = head;  // Сохраняем текущий head
        head = head->next;  // Перемещаем head на следующий элемент
        delete temp->data;  // Освобождаем память для данных
        delete temp;  // Освобождаем память для узла
        count--;  // Уменьшаем счетчик элементов
        if (count == 0) {  // Если список стал пустым
            tail = nullptr;  // Обнуляем tail
        }
    }
}
// удаление всех элементов из списка
void Keeper::delete_all() {
    while (head != 0)
        delete_head();
    
}
// Печатаем содержимое контейнера
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
// Возвращение количества элементов в контейнере
int Keeper::get_count() {
    return count;
}
// Добавление нового элемента в конец списка
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
// Удаление элемента по индексу n
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
// Редактирование элемента 
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
// Сохранение данных в файл
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
// Загрузка данных из файла
void Keeper::load(const string& filename) {
    ifstream in(filename);  // Открываем файл для чтения
    if (!in) {  
        cerr << "Ошибка открытия файла для загрузки!" << endl;  
        return;  
    }
    string marker;  // Переменная для хранения типа объекта
    while (getline(in, marker)) {  // Читаем строки из файла
        if (!marker.empty() && marker.back() == '\r') {  // Убираем лишний символ
            marker.pop_back();  // Удаляем последний символ
        }
        Ship* temp = nullptr;  // Указатель на временный объект Ship
        // Определяем тип объекта и создаем его
        if (marker == "Speedboat") {
            temp = new Speedboat();  
        } else if (marker == "Sailboat") {
            temp = new Sailboat();  
        } else if (marker == "Submarine") {
            temp = new Submarine();  
        } else {
            cerr << "Неизвестный тип объекта: " << marker << endl;  
            continue;  // Переходим к следующей строке
        }
        if (temp) {  // Если объект успешно создан
            temp->load(in);  // Загружаем данные в объект
            cout << "Объект добавлен в контейнер" << endl;  
            this->add(temp);  // Добавляем объект в контейнер
        }
    }
    in.close();  // Закрываем файл
}
// Оператор логического отрицания для изменения порядка элементов
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
// Оператор разыменования, удаляет первый элемент из контейнера
Keeper& Keeper::operator*() {
    this->delete_head(); 
    cout << "Первый элемент удален из контейнера оператором '*'" << endl;
    return *this;
}