#pragma once
#include "BaseClass.h"
#include "string"

//наследование - использование доступных свойств
// и методов класса родителям (parent), классом наследником(child)
class Warrior : public virtual Npc //наследование с модификатором доступа public
{
protected:  //модификатор 0 (приватный - защищенный, доступ к полям, только внутри класса)
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    //конструктор - метод, который вызывается в момент создания экземпляра
    //класса (вручную вызвать в основном потоке программы не можем)
    bool Save() override;
    bool Load() override;
    Warrior();
    Warrior(string name, unsigned int health, float damage);

    void GetWeapons();
    void GetInfo();
    void Create() override;
    
   

    bool operator == (const Warrior& warrior) const;
    Warrior& operator = (const Npc& npc);
 
        ~Warrior();
};


//virtual - создает виртуализацию методов, классов
//при этом сам класс повторно не создается
class Wizard : public virtual Npc
{

    class Spell
    {
        protected:
            string name{"заклинание"};
            unsigned short damage{0};
            unsigned short price{0};
            bool isCurse{false};
            int timeCast{ 0 };
          
        public:
            Spell(string name = "заклинание", unsigned short damage = 0, 
                unsigned short price = 0, bool isCurse = false, int timeCast = 0);

            string GetName() const { return name; }
            unsigned short GetDamage() const { return damage; }
            unsigned short GetPrice() const { return price; }
            bool IsCurse() const { return isCurse; }
            int GetTimeCast() const { return timeCast; }
            
            unsigned short CastSpell();
           

    };
protected:
    unsigned short intellect = 27;
    Spell spells[5] = { 
        Spell("Насмешка", 32,52,false,23),
        Spell("DOMEIN EXPENSION", 1000,99,false,100), 
        Spell("Яд гооргоны", 15,30,false,80),
        Spell("ахатыбд", 999,0,false,52),
        Spell("Священый меч эсканор", 100,25,false,0),
    };
public:
    Wizard()
    {
        name = "волшебник";
        health = 23;
        damage = 15;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "кастомный конструктор волшебника" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetInfo(); 

    void GetSpellInfo();
   
    void Create() override;
    
    bool operator == (const Wizard& wizard) const;
   
    void operator = (Npc npc);
   
    bool Save() override;
    bool Load() override;
    ~Wizard(); //деструктор всегда без аргументов
   

};

//множественное наследование

class Paladin : public Warrior, public Wizard
{
public:
    Paladin();
    void GetInfo();
    void Create() override;
    bool operator == (const Paladin& paladin) const;
    Paladin& operator = (const Npc& npc);
    bool Save() override;
    bool Load() override;
};








