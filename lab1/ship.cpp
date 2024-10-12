#include "ship.h"

Ship::Ship() {cout << "Ship: Конструктор без параметров\n";}

Ship::Ship(const string& n) : name(n) {cout << "Ship: Конструктор с параметрами\n";}

Ship::Ship(const Ship& other) {cout << "Ship: Конструктор копирования\n";}

Ship::~Ship() {cout << "Ship: Деструктор\n";}