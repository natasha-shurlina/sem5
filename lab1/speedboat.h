#pragma once
#include "ship.h"
#include <cstdlib>
// Катер
class Speedboat: public Ship
{
private:
    string purpose; // Назначение
    string material; // Материал корпуса
    string driving_qualities; // Ходовые качества
    float speed; // Скорость
    int people; // Количество людей, которые могу находится на борты
public:
    Speedboat();
    Speedboat(const string& purpose, const string& material, const string& driving_qualities, const float& speed, const int& people);
    Speedboat(const Speedboat& other);
    void set_purpose(string p);
    string get_purpose();
    void set_material(string m);
    string get_material();
    void set_driving_qualities(string d);
    string get_driving_qualities();
    void set_speed(float s);
    float get_speed();
    void set_people(int p);
    int get_people();
    void input_info() override;
    void display() override;
    void change_info() override;
    void save(ostream&) override;
    void load(istream&) override;
    ~Speedboat();
};