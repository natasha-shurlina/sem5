#include "ship.h"

Ship::Ship() {cout << "Конструктор без параметров для Ship\n";}

Ship::Ship(const string& n) : name(n) {cout << "Конструктор с параметрами для Ship\n";}

Ship::Ship(const Ship& other) {cout << "Конструктор копирования для Ship\n\n";}

Ship::~Ship() {cout << "Деструктор для Ship\n\n";}