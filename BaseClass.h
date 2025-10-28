
#pragma once
#include <iostream>

using namespace std;

class Npc
{
protected: //модификатор 0 защищенный (дает доступ внутри класса родителя и наследника)
           //но все еще не дает доступ в основном потоке программы

    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
   
public:    //публичный модификатор доступ (использовать метод можно в любом месте)
   
    virtual void GetInfo() //метод класса
    {
        cout << "Имя - " << name << endl;
        cout << "Здоровье - " << health << endl;
        cout << "Урон - " << damage << endl;
    }
    
    virtual void Create() {};
};
class Player
{
public:
    void Create(Npc* player)
    {
        player->Create();
    }
};