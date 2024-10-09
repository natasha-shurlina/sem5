#include "sailboat.h"
#include <iostream>
#include <string>

using namespace std;

Sailboat::Sailboat() : type(""), name(""), purpose(""), length(0), speed(0), crew("") {}

Sailboat::Sailboat(const string& t, const string& n, const string& pur, const float& len, const float& sp, const string& cr)
    : type(t), name(n), purpose(pur), length(len), speed(sp), crew(cr) {}

Sailboat::Sailboat(const Sailboat& other)
    : type(other.type), name(other.name), purpose(other.purpose), length(other.length), speed(other.speed), crew(other.crew) {}

void Sailboat::set_type(string t) {
    type = t;
}

string Sailboat::get_type() {
    return type;
}

void Sailboat::set_name(string n) {
    name = n;
}

string Sailboat::get_name() {
    return name;
}

void Sailboat::set_purpose(string p) {
    purpose = p;
}

string Sailboat::get_purpose() {
    return purpose;
}

void Sailboat::set_length(float l) {
    length = l;
}

float Sailboat::get_length() {
    return length;
}

void Sailboat::set_speed(float s) {
    speed = s;
}

float Sailboat::get_speed() {
    return speed;
}

void Sailboat::set_crew(string c) {
    crew = c;
}

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
    cout << "Команда: " << crew << "\n";
}

void Sailboat::change_info() {
    int choice;
    cout << "Что вы хотите изменить?\n";
    cout << "1. Тип\n2. Имя\n3. Цель\n4. Длина\n5. Скорость\n6. Команда\n";
    cout << "Введите номер: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            string newType;
            cout << "Введите новый тип: ";
            getline(cin, newType);
            set_type(newType);
            break;
        }
        case 2: {
            string newName;
            cout << "Введите новое имя: ";
            getline(cin, newName);
            set_name(newName);
            break;
        }
        case 3: {
            string newPurpose;
            cout << "Введите новую цель: ";
            getline(cin, newPurpose);
            set_purpose(newPurpose);
            break;
        }
        case 4: {
            float newLength;
            cout << "Введите новую длину: ";
            cin >> newLength;
            set_length(newLength);
            break;
        }
        case 5: {
            float newSpeed;
            cout << "Введите новую скорость: ";
            cin >> newSpeed;
            set_speed(newSpeed);
            break;
        }
        case 6: {
            string newCrew;
            cout << "Введите новую команду: ";
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

Sailboat::~Sailboat() {}
