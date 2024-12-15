#include "container.h"

Container::Container() : head(nullptr), tail(nullptr), count(0) {
    cout << "Конструктор без параметров для класса Container вызван\n";}

Container::Container(Node* h, Node* t, const int c) : head(h), tail(t), count(c) {
    cout << "Конструктор с параметрами для класса Container вызван\n";
}

Container::Container(const Container& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Конструктор копирования для класса Container вызван\n";
}

Container::~Container() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    tail = nullptr;
    count = 0;
    cout << "Деструктор для класса Container вызван" << endl;
}

Node* Container::get_head() {
    return this->head;
}

Node* Container::get_tail() {
    return this->tail;
}

void Container::add_group(Group* St, int index) {
    if (index < 0 || index > count) {
        throw out_of_range("Индекс все диапазона");
    }
    
    Node* node_to_add = new Node;
    node_to_add->data = St;
    node_to_add->next = nullptr;

    if (index == 0) {
        node_to_add->next = head;
        head = node_to_add;
        if (count == 0) {
            tail = node_to_add;
        }
    } else {
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        node_to_add->next = prev->next;
        prev->next = node_to_add;
        
        if (node_to_add->next == nullptr) {
            tail = node_to_add;
        }
    }
    
    ++count;
}

Container& Container::delete_group(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Индекс все диапазона");
    }

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp->data;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp->data;
        delete temp;
    }

    --count;
    return *this;
}

void Container::display_groups() {
    Node* temp = head;
    if (count == 0) {
        cout << "Нет данных" << endl;
        return;
    }

    int index = 1;
    while (temp != nullptr) {
        cout << index << " - группа:\n";
        temp->data->display_group();
        temp = temp->next;
        index++;
    }
}

void Container::sort_groups_by_number() {
    if (count < 2) return;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data->get_number() > j->data->get_number()) { 
                Group* temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void Container::search_groups_with_average_marks_more_than_4() {
    Node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data->get_aver_mark() > 4.0) {
            cout << "Группа с номером " << temp->data->get_number() 
                 << " имеет среднюю оценку больше чем 4: " 
                 << temp->data->get_aver_mark() << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Групп со средней оценкой больше 4 не было найдено." << endl;
    }
}

Container& Container::edit_group(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Индекс все диапазона");
    }
    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    while (true) {
        cout << "\n===== Меню управления студентами =====" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Удалить студента" << endl;
        cout << "3. Редактирование данных ученика" << endl;
        cout << "4. Вывести данные о группе" << endl;
        cout << "5. Редактирование предмета" << endl;
        cout << "6. Редактирования номера" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите Ваш выбор: ";
        int choice = check_input();

        switch (choice) {
            case 1: {
                string name;
                int size;
                cout << "Введите имя студента: ";
                cin.ignore();
                getline(cin, name);
                cout << "Введите количество оценок: ";
                size = check_input();

                float* marks = new float[size];

                cout << "Введите оценку: ";
                for (int i = 0; i < size; i++) {
                    cin >> marks[i];
                }

                cout << "Введите индекс студента для добавления: ";
                int student_index = check_input();

                Student* new_student = new Student(name, marks, size);
                temp->data->add_student(new_student, student_index - 1);
                cout << "Студент добавлен." << endl;
                break;
            }
            case 2: {
                int student_index;
                cout << "Введите индекс студента для удаления: ";
                student_index = check_input();
                try {
                    temp->data->delete_student(student_index - 1);
                    cout << "Студент удален." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                int student_index;
                cout << "Введите индекс студента для редактирования: ";
                student_index = check_input();
                try {
                    temp->data->edit_student(student_index - 1);
                    cout << "Данные о студенте обновлены." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                temp->data->display_group();
                break;
            }
            case 5: {
                cout << "Введите количество предметов: ";
                int subject_count = check_input();

                string* subjects = new string[subject_count];
                cout << "Введите название предмета:" << endl;
                for (int i = 0; i < subject_count; ++i) {
                    cin >> subjects[i];
                }
                temp->data->set_subjects(subjects, subject_count);
                break;
            }
            case 6: {
                cout << "Введите новый номер: ";
                int num = check_input();
                temp->data->set_number(num);
                break;
            }
            case 0: {
                cout << "Выход из меню." << endl;
                return *this;
            }
            default: {
                cout << "Ошибка! Попробуйте еще раз." << endl;
                break;
            }
        }
    }
}


Group& Container::operator[](int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Индекс все диапазона");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    return *temp->data;
}

