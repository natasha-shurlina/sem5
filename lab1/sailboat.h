#pragma once
#include "ship.h"
#include <cstdlib>

class Sailboat: public Ship
{
private:
    string type;
    string name;
    string purpose;
    float length;
    float speed;
    string crew;
public:
    Sailboat();
    Sailboat(const string& type, const string& name, const string& pur, const float& len, const float& sp, const string& crew);
    Sailboat(const Sailboat& other);
    void set_type(string t);
    string get_type();
    void set_name(string n);
    string get_name();
    void set_purpose(string p);
    string get_purpose();
    void set_length(float l);
    float get_length();
    void set_speed(float s);
    float get_speed();
    void set_crew(string c);
    string get_crew();
    void input_info() override;
    void display() override;
    void change_info() override;
    void save(ostream&) override;
    void load(istream&) override;
    ~Sailboat();
};