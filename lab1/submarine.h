#pragma once
#include "ship.h"
#include <cstdlib>

class Submarine: public Ship
{
private:
    float length;
    float width;
    string crew;
    string time;
    float speed;
    string weapon;
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
    void display() override;
    void change_info() override;
    void save(ostream&) override;
    void load(istream&) override;
    ~Submarine();
};