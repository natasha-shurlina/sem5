#include "submarine.h"//подводная лодка
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Submarine::Submarine() : length(0), width(0), crew(""), time(""), speed(0), weapon("") {cout << "Submarine: Конструктор без параметров\n";}

Submarine::Submarine(const float& len, const float& wid, const string& cr, const string& ti, const float& sp, const string& weap)
    : length(len), width(wid), crew(cr), time(ti), speed(sp), weapon(weap) {cout << "Submarine: Конструктор с параметрами\n";}

Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crew(other.crew), time(other.time), speed(other.speed), weapon(other.weapon) {cout << "Submarine: Конструктор копирования\n";}

void Submarine::set_length(float len) {
    length = len;
}//длина

float Submarine::get_length() {
    return length;
}

void Submarine::set_width(float wid) {
    width = wid;
}//ширина

float Submarine::get_width() {
    return width;
}

void Submarine::set_crew(string cr) {
    crew = cr;
}//экмипаж

string Submarine::get_crew() {
    return crew;
}

void Submarine::set_time(string ti) {
    time = ti;
}//время неприрывного пребывания под водой

string Submarine::get_time() {
    return time;
}

void Submarine::set_speed(float sp) {
    speed = sp;
}//максимальная подводная скорость

float Submarine::get_speed() {
    return speed;
}

void Submarine::set_weapon(string weap) {
    weapon = weap;
}//вооружение

string Submarine::get_weapon() {
    return weapon;
}

void Submarine::display() {
    cout << "Информация о подводной лодке:\n";
    cout << "Длина: " << length << " м\n";
    cout << "Ширина: " << width << " м\n";
    cout << "Команда: " << crew << "\n";
    cout << "Время плавания: " << time << "\n";
    cout << "Скорость: " << speed << " узлов\n";
    cout << "Оружие: " << weapon << "\n";
}

void Submarine::change_info() {
    int choice;
    cout << "1. Длина\n2. Ширина\n3. Команда\n4. Время плавания\n5. Скорость\n6. Оружие\n";
    cout << "Введите номер: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            float newLength;
            cout << "Введите длину: ";
            cin >> newLength;
            set_length(newLength);
            break;
        }
        case 2: {
            float newWidth;
            cout << "Введите ширину: ";
            cin >> newWidth;
            set_width(newWidth);
            break;
        }
        case 3: {
            string newCrew;
            cout << "Введите команду: ";
            getline(cin, newCrew);
            set_crew(newCrew);
            break;
        }
        case 4: {
            string newTime;
            cout << "Введите время плавания: ";
            getline(cin, newTime);
            set_time(newTime);
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
            string newWeapon;
            cout << "Введите оружие: ";
            getline(cin, newWeapon);
            set_weapon(newWeapon);
            break;
        }
        default:
            cout << "Неверный выбор.\n";
            break;
    }
}

void Submarine::save(ostream& out) {
    out << "Submarine\n";
    out << length << '\n' << width << '\n' << crew << '\n' << time << '\n' << speed << '\n' << weapon << '\n';
}

void Submarine::load(istream& in) {
    in >> length;
    in.ignore();
    in >> width;
    in.ignore();
    getline(in, crew);
    getline(in, time);
    in >> speed;
    in.ignore();
    getline(in, weapon);
}

void Submarine::input_info() {
    string weapon, time, crew;
    float length, width, speed;

    cout << "Введите длину: ";
    while (!(cin >> length)) {
        cout << "Ошибка ввода. Пожалуйста, введите число для длины: ";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    set_length(length);
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    cout << "Введите ширину: ";
    while (!(cin >> width)) {
        cout << "Ошибка ввода. Пожалуйста, введите число для ширины: ";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    set_width(width);
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    cout << "Введите экипаж: ";
    getline(cin, crew);
    set_crew(crew);

    cout << "Введите время: ";
    getline(cin, time);
    set_time(time);

    cout << "Введите скорость: ";
    while (!(cin >> speed)) {
        cout << "Ошибка ввода. Пожалуйста, введите число для скорости: ";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    set_speed(speed);
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    cout << "Введите оружие: ";
    getline(cin, weapon);
    set_weapon(weapon);
}

Submarine::~Submarine() {cout << "Submarine: Деструктор\n";}
