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
    void GetInfo() override; 
    void Create() override;
    
   

    bool operator == (const Warrior& warrior) const;
    void operator = (const Npc& npc);
 
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
            Spell(string name = "заклинание", unsigned short damage = 0, unsigned short price = 0, bool isCurse = false, int timeCast = 0);
          
            string operator[](unsigned index) const;
            
            
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
    void GetInfo() override; 

    void GetSpellInfo();
   
    void Create() override;
    
    bool operator == (const Wizard& wizard) const;
   
    void operator = (Npc npc);
   
    bool Save() override;
   
    ~Wizard(); //деструктор всегда без аргументов
   

};

//множественное наследование
class Paladin : public Warrior, public Wizard
    //следующий родительственный класс добавляется через запятую
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
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания в книге заклинаний - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void Create() override
    {
        cout << "Вы создали паладина" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    bool operator == (const Paladin& paladin) const
    {
        return ((paladin.damage == this->damage) && (paladin.health == this->health)
            && (paladin.intellect == this->intellect)) && (paladin.strenght == this->strenght);
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
    bool Save() override
    {


        if (Npc::Save())
        {
            ofstream saveSystem("save.bin", ios::binary);
            if (saveSystem.is_open())
            {

                saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
                for (int i = 0; i < 4; i++)
                {
                    saveSystem.write(reinterpret_cast<const char*>(&spell[i]), sizeof(spell[i]));
                }
                saveSystem.close();
                return true;
            }
            else
            {
                cout << "сохранение не удалось" << endl;
                return false;
            }
        }
    }
};







