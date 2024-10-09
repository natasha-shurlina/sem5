#include "speedboat.h"
#include <iostream>
#include <string>

using namespace std;

Speedboat::Speedboat() : purpose(""), material(""), driving_qualities(""), speed(0), people(0) {}

Speedboat::Speedboat(const string& pur, const string& mat, const string& drq, const float& sp, const int& peop)
    : purpose(pur), material(mat), driving_qualities(drq), speed(sp), people(peop) {}

Speedboat::Speedboat(const Speedboat& other)
    : purpose(other.purpose), material(other.material), driving_qualities(other.driving_qualities), speed(other.speed), people(other.people) {}

void Speedboat::set_purpose(string p) {
    purpose = p;
}

string Speedboat::get_purpose() {
    return purpose;
}

void Speedboat::set_material(string m) {
    material = m;
}

string Speedboat::get_material() {
    return material;
}

void Speedboat::set_driving_qualities(string d) {
    driving_qualities = d;
}

string Speedboat::get_driving_qualities() {
    return driving_qualities;
}

void Speedboat::set_speed(float s) {
    speed = s;
}

float Speedboat::get_speed() {
    return speed;
}

void Speedboat::set_people(int p) {
    people = p;
}

int Speedboat::get_people() {
    return people;
}

void Speedboat::display() {
    cout << "Информация о катере:\n";
    cout << "Цель: " << purpose << "\n";
    cout << "Материал: " << material << "\n";
    cout << "Характеристики вождения: " << driving_qualities << "\n";
    cout << "Скорость: " << speed << " узлов\n";
    cout << "Количество людей: " << people << "\n";
}

void Speedboat::change_info() {
    int choice;
    cout << "Что вы хотите изменить?\n";
    cout << "1. Цель\n2. Материал\n3. Характеристики вождения\n4. Скорость\n5. Количество людей\n";
    cout << "Введите номер: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            string newPurpose;
            cout << "Введите новую цель: ";
            getline(cin, newPurpose);
            set_purpose(newPurpose);
            break;
        }
        case 2: {
            string newMaterial;
            cout << "Введите новый материал: ";
            getline(cin, newMaterial);
            set_material(newMaterial);
            break;
        }
        case 3: {
            string newDrivingQualities;
            cout << "Введите новые характеристики вождения: ";
            getline(cin, newDrivingQualities);
            set_driving_qualities(newDrivingQualities);
            break;
        }
        case 4: {
            float newSpeed;
            cout << "Введите новую скорость: ";
            cin >> newSpeed;
            set_speed(newSpeed);
            break;
        }
        case 5: {
            int newPeople;
            cout << "Введите новое количество людей: ";
            cin >> newPeople;
            set_people(newPeople);
            break;
        }
        default:
            cout << "Неверный выбор.\n";
            break;
    }
}

void Speedboat::save(ostream& out) {
    out << "Speedboat\n";
    out << purpose << '\n' << material << '\n' << driving_qualities << '\n' << speed << '\n' << people << '\n';
}

void Speedboat::load(istream& in) {
    getline(in, purpose);
    getline(in, material);
    getline(in, driving_qualities);
    in >> speed;
    in.ignore();
    in >> people;
    in.ignore();
}

Speedboat::~Speedboat() {}
