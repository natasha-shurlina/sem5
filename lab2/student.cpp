#include "student.h"

Student::Student() : name(""), marks(nullptr), size(0) {
    cout << "Конструктор без параметров для класса Student вызван\n";
}

Student::Student(const string& n, const float* m, const int& siz)
    : name(n), size(siz) {
    marks = new float[size];
    copy(m, m + size, marks);
    cout << "Конструктор с параметрами для класса Student вызван\n";
}


Student::Student(const Student& other) : name(other.name), size(other.size) {
    marks = new float[size];
    copy(other.marks, other.marks + size, marks);
    cout << "Конструктор копирования для класса Student вызван\n";
}


Student::~Student() {
    delete[] marks;
    cout << "Деструктор для класса Student вызван\n";
}

string Student::get_name() const{
    return this->name;
}

void Student::set_name(const string& n) {
    this->name = n;
}

const float* Student::get_marks() const { 
    return marks; 
}

void Student::set_marks(const float* m, int siz) {
    delete[] marks;
    size = siz;
    marks = new float[size];
    memcpy(marks, m, size * sizeof(float));
}

int Student::get_size() const { 
    return size; 
}

void Student::set_size(const int& siz) { 
    size = siz; 
}

void Student::display_student() {
    cout << "Имя: " << name;
    cout << "\nОценки: ";
    for (int i = 0; i < size; i++) cout << marks[i] << ' ';
    cout << endl;
}

void Student::edit_student() {
    int choice;
    cout << "Выберите, что Вы хотите отредактировать:\n";
    cout << "1. Имя студента\n";
    cout << "2. Список оценок\n";
    cout << "Введите Ваш выбор: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string new_name;
            cout << "Введите новое имя студента: ";
            cin.ignore();
            getline(cin, new_name);
            set_name(new_name);
            break;
        }
        case 2: {
            int new_size;
            cout << "Введите количество оценок: ";
            new_size = check_input();
            float* new_marks = new float[new_size];
            cout << "Введите оценки: ";
            for (int i = 0; i < new_size; i++) {
                cin >> new_marks[i];
            }
            set_marks(new_marks, new_size);
            delete[] new_marks;
            break;
        }

        default:
            cout << "Ошибка выбора!" << endl;
    }
}