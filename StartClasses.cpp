#include "StartClasses.h"
bool Warrior::Save() 
{


    
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (Npc::Save())
        {
            cout << "сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "сохранение не удалось" << endl;
        return false;
    }
    
};
bool Warrior::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
   
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "связь с базой нарушена\nПамять утерена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));
       
    }
    else
    {
        cout << "связь с базой нарушена\nПамять утерена" << endl;
        return false;
    }
    loadSystem.close();
    return true;


};
Warrior::Warrior() //конструктор по умолчанию, когда нет аргументов
{
    name = "воин";
    health = 35;
    damage = 10;
}

Warrior::Warrior(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор война" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Warrior::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1];
}
void Warrior::GetInfo()   //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Сила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << endl;
    }
}
void Warrior::Create() 
{
    cout << "Вы создали война" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
bool Warrior::operator == (const Warrior& warrior) const
{
    return (warrior.damage == this->damage) &&
           (warrior.health == this->health) &&
           (warrior.strenght == this->strenght);
}
void  Warrior::operator = (const Npc& npc)
{
    if (this != &npc)
    {
        this->name = npc.GetName();
        this->health = npc.GetHealth();
        this->damage = npc.GetDamage();
        this->lvl = npc.GetLvl();
        return *this;
    }
}


Warrior::~Warrior() //деструктор всегда без аргументов
{
    cout << name << " пал смертью храбрых" << endl;
}

   
void Wizard::GetInfo() //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Интеллект - " << intellect << endl;
    cout << "Доступные заклинания в книге заклинаний - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << spell[i] << endl;
    }
}
void Wizard::CastSpell()
{
    cout << name << " применяет " << spell[lvl - 1] << endl;
}
void Wizard::Create()
{
    cout << "Вы создали волшебника" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    CastSpell();
}
bool Wizard::operator == (const Wizard& wizard) const
{
    return ((wizard.damage == this->damage) && (wizard.health == this->health)
        && (wizard.intellect == this->intellect));
}
void Wizard::operator = (Npc npc)
{
    this->name = npc.GetName();
    this->name = npc.GetHealth();
    this->name = npc.GetDamage();
    this->name = npc.GetLvl();
}
bool Wizard::Save() 
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
Wizard::~Wizard() //деструктор всегда без аргументов
{
    cout << name << " испустил дух" << endl;
}
