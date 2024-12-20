#pragma once
#include "ship.h"
#include <cstdlib>

class Submarine: public Ship
{
private:
    float length; // Длина
    float width; // Ширина
    string crew; //Экипаж
    string time; //Время неприрывного пребывания под водой
    float speed; // Максимальная скорость под водой
    string weapon; //Вооружение
public:
    Submarine();
    Submarine(const float& len, const float& wid, const string& cr, const string& ti, const float& sp, const string& weap);
    Submarine(const Submarine& other);
    void set_length(float length);
    float get_length();
    void set_width(float width);
    float get_width();
    void set_crew(string crew);
    string get_crew();
    void set_time(string time);
    string get_time();
    void set_speed(float speed);
    float get_speed();
    void set_weapon(string weapon);
    string get_weapon();
    void input_info() override;
    void display() override;
    void change_info() override;
    void save(ostream&) override;
    void load(istream&) override;
    ~Submarine();
};