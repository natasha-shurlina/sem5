#pragma once
#include <string>
#include <iostream>
using namespace std;

class Ship
{
private:
    string name;
public:
    Ship();
    Ship(const string& n);
    Ship(const Ship& other);
    virtual void input_info() = 0;
    virtual void display() = 0;
    virtual void change_info() = 0;
    virtual void save(ostream&) = 0;
    virtual void load(istream&) = 0;
    virtual ~Ship();
};