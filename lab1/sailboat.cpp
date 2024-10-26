#include "sailboat.h" //парусник
#include <iostream>
#include <string>
#include <limits>   

using namespace std;
// Конструктор без параметров
Sailboat::Sailboat() : type(""), name(""), purpose(""), length(0), speed(0), crew("") {cout << "Sailboat: Конструктор без параметров\n";}
// Конструктор с параметрами
Sailboat::Sailboat(const string& t, const string& n, const string& pur, const float& len, const float& sp, const string& cr)
    : type(t), name(n), purpose(pur), length(len), speed(sp), crew(cr) {cout << "Sailboat: Конструктор с параметрами\n";}
// Конструктор копирования
Sailboat::Sailboat(const Sailboat& other)
    : type(other.type), name(other.name), purpose(other.purpose), length(other.length), speed(other.speed), crew(other.crew) {cout << "Sailboat: Конструктор копирования\n";}

void Sailboat::set_type(string t) {
    type = t;
}//тип парусника

string Sailboat::get_type() {
    return type;
}

void Sailboat::set_name(string n) {
    name = n;
}//название парусника

string Sailboat::get_name() {
    return name;
}

void Sailboat::set_purpose(string p) {
    purpose = p;
}//мирный или военный

string Sailboat::get_purpose() {
    return purpose;
}

void Sailboat::set_length(float l) {
    length = l;
}//длина корпуса

float Sailboat::get_length() {
    return length;
}

void Sailboat::set_speed(float s) {
    speed = s;
}//скорость перемещенияч

float Sailboat::get_speed() {
    return speed;
}

void Sailboat::set_crew(string c) {
    crew = c;
}//экипаж

string Sailboat::get_crew() {
    return crew;
}

void Sailboat::display() {
    cout << "Информация о паруснике:\n";
    cout << "Тип: " << type << "\n";
    cout << "Имя: " << name << "\n";
    cout << "Цель: " << purpose << "\n";
    cout << "Длина: " << length << " м\n";
    cout << "Скорость: " << speed << " узлов\n";
    cout << "Экипаж: " << crew << "\n";
}

void Sailboat::change_info() {
    int choice;
    cout << "1. Тип\n2. Имя\n3. Цель\n4. Длина\n5. Скорость\n6. Команда\n";
    cout << "Введите номер: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            string newType;
            cout << "Введите тип: ";
            getline(cin, newType);
            set_type(newType);
            break;
        }
        case 2: {
            string newName;
            cout << "Введите имя: ";
            getline(cin, newName);
            set_name(newName);
            break;
        }
        case 3: {
            string newPurpose;
            cout << "Введите цель (мирный/военный): ";
            getline(cin, newPurpose);
            set_purpose(newPurpose);
            break;
        }
        case 4: {
            float newLength;
            cout << "Введите длину: ";
            cin >> newLength;
            set_length(newLength);
            break;
        }
        case 5: {
            float newSpeed;
            cout << "Введите скорость: ";
            cin >> newSpeed;
            set_speed(newSpeed);
            break;
        }
        case 6: {
            string newCrew;
            cout << "Введите экипаж: ";
            getline(cin, newCrew);
            set_crew(newCrew);
            break;
        }
        default:
            cout << "Неверный выбор.\n";
            break;
    }
}

void Sailboat::save(ostream& out) {
    out << "Sailboat\n";
    out << type << '\n' << name << '\n' << purpose << '\n' << length << '\n' << speed << '\n' << crew << '\n';
}

void Sailboat::load(istream& in) {
    getline(in, type);
    getline(in, name);
    getline(in, purpose);
    in >> length;
    in.ignore();
    in >> speed;
    in.ignore();
    getline(in, crew);
}

void Sailboat::input_info() {
    string type, name, purpose, crew;
    float length, speed;

    cin.ignore();
    cout << "Введите тип: ";
    getline(cin, type);
    set_type(type);

    cout << "Введите название: ";
    getline(cin, name);
    set_name(name);

    cout << "Введите назначение (мирный/военный): ";
    getline(cin, purpose);
    set_purpose(purpose);

    cout << "Введите экипаж: ";
    getline(cin, crew);
    set_crew(crew);

    cout << "Введите длину: ";
    while (!(cin >> length)) {
        cout << "Ошибка ввода. Пожалуйста, введите число для длины: ";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    set_length(length);
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    cout << "Введите скорость: ";
    while (!(cin >> speed)) {
        cout << "Ошибка ввода. Пожалуйста, введите число для скорости: ";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    set_speed(speed);
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}



Sailboat::~Sailboat() {cout << "Sailboat: Деструктор\n";}
