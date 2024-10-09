#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "sailboat.h"
#include "ship.h"
#include "speedboat.h"
#include "submarine.h"
using namespace std;

struct Node {
    Node* next;
    Ship* data;
};

class Keeper    
{
private:
    Node* head;
    Node* tail;
    int count;

public:
    Keeper();
    Keeper(Node* h, Node* t, int c);
    Keeper(Keeper& other);
    void delete_head();
    void delete_all();
    void print_keeper();
    int get_count();
    friend Keeper& operator--(Keeper& K);
    friend Keeper& operator*(Keeper& K);
    void add(Ship* mover);
    Keeper& delete_Node(int n);
    Keeper& edit_Node(int n);
    void save(const string& filename);
    void load(const string& filename);
    ~Keeper();
};