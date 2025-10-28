#pragma once
#include "BaseClass.h"

//наследование - использование доступных свойств
// и методов класса родител€м (parent), классом наследником(child)
class Warrior : protected virtual Npc //наследование с модификатором доступа public
{
protected:  //модификатор 0 (приватный - защищенный, доступ к пол€м, только внутри класса)
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    //конструктор - метод, который вызываетс€ в момент создани€ экземпл€ра
    //класса (вручную вызвать в основном потоке программы не можем)

    Warrior() //конструктор по умолчанию, когда нет аргументов
    {
        name = "воин";
        health = 35;
        damage = 10;
    }
    //кастомный конструктор
    Warrior(string name, unsigned int health, float damage)
    {
        cout << "кастомный конструктор война" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetWeapons()
    {
        cout << name << " вз€л в руки " << weapons[lvl - 1];
    }
    void GetInfo() override  //полиморфизм (перегрузка дл€ метода)
    {
        Npc::GetInfo();
        cout << "—ила - " << strenght << endl;
        cout << "ƒоступное оружие - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << weapons[i] << endl;
        }
    }
    void Create() override
    {
        cout << "¬ы создали война" << endl;
        cout << "¬ведите им€ персонажа\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    //перегрузка операторов
    //перегрузка оператора сравнени€ (==)
    
    bool operator == (const Warrior& warrior) const
    {
        return ((warrior.damage == this->damage) && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    }


    //деструктор - метод, который вызываетс€ автоматически при высвобождении пам€ти
    //при окончании работы с экземпл€ром класса (нельз€ вызвать вручную)
    ~Warrior() //деструктор всегда без аргументов
    {
        cout << name << " пал смертью храбрых" << endl;
    }
};


//virtual - создает виртуализацию методов, классов
//при этом сам класс повторно не создаетс€
class Wizard : protected virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "вспышка", "магисческа€ стрела", "огненный шар", "метеоритный дождь" };
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
    void GetInfo() override  //полиморфизм (перегрузка дл€ метода)
    {
        Npc::GetInfo();
        cout << "»нтеллект - " << intellect << endl;
        cout << "ƒоступные заклинани€ в книге заклинаний - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void CastSpell()
    {
        cout << name << " примен€ет " << spell[lvl - 1] << endl;
    }
    void Create() override
    {
        cout << "¬ы создали волшебника" << endl;
        cout << "¬ведите им€ персонажа\t";
        cin >> name;
        GetInfo();
        CastSpell();
    }
    ~Wizard() //деструктор всегда без аргументов
    {
        cout << name << " испустил дух" << endl;
    }
};

//множественное наследование
class Paladin : public Warrior, public Wizard
    //следующий родительственный класс добавл€етс€ через зап€тую
{
public:
    Paladin()
    {
        name = "паладин";
        health = 25;
        damage = 12;
        strenght = 27;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "»нтеллект - " << intellect << endl;
        cout << "ƒоступные заклинани€ в книге заклинаний - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void Create() override
    {
        cout << "¬ы создали паладина" << endl;
        cout << "¬ведите им€ персонажа\t";
        cin >> name;
        GetInfo();
        CastSpell();
        GetWeapons();
    }
};
