#pragma once
#include "BaseClass.h"

//������������ - ������������� ��������� �������
// � ������� ������ ��������� (parent), ������� �����������(child)
class Warrior : protected virtual Npc //������������ � ������������� ������� public
{
protected:  //����������� 0 (��������� - ����������, ������ � �����, ������ ������ ������)
    unsigned short strenght{ 31 };
    string weapons[4] = { "������", "�������", "������", "���" };
public:
    //����������� - �����, ������� ���������� � ������ �������� ����������
    //������ (������� ������� � �������� ������ ��������� �� �����)

    Warrior() //����������� �� ���������, ����� ��� ����������
    {
        name = "����";
        health = 35;
        damage = 10;
    }
    //��������� �����������
    Warrior(string name, unsigned int health, float damage)
    {
        cout << "��������� ����������� �����" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetWeapons()
    {
        cout << name << " ���� � ���� " << weapons[lvl - 1];
    }
    void GetInfo() override  //����������� (���������� ��� ������)
    {
        Npc::GetInfo();
        cout << "���� - " << strenght << endl;
        cout << "��������� ������ - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << weapons[i] << endl;
        }
    }
    void Create() override
    {
        cout << "�� ������� �����" << endl;
        cout << "������� ��� ���������\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    //���������� ����������
    //���������� ��������� ��������� (==)
    
    bool operator == (const Warrior& warrior) const
    {
        return ((warrior.damage == this->damage) && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    }


    //���������� - �����, ������� ���������� ������������� ��� ������������� ������
    //��� ��������� ������ � ����������� ������ (������ ������� �������)
    ~Warrior() //���������� ������ ��� ����������
    {
        cout << name << " ��� ������� �������" << endl;
    }
};


//virtual - ������� ������������� �������, �������
//��� ���� ��� ����� �������� �� ���������
class Wizard : protected virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "�������", "����������� ������", "�������� ���", "����������� �����" };
public:
    Wizard()
    {
        name = "���������";
        health = 23;
        damage = 15;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "��������� ����������� ����������" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    void GetInfo() override  //����������� (���������� ��� ������)
    {
        Npc::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� � ����� ���������� - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void CastSpell()
    {
        cout << name << " ��������� " << spell[lvl - 1] << endl;
    }
    void Create() override
    {
        cout << "�� ������� ����������" << endl;
        cout << "������� ��� ���������\t";
        cin >> name;
        GetInfo();
        CastSpell();
    }
    ~Wizard() //���������� ������ ��� ����������
    {
        cout << name << " �������� ���" << endl;
    }
};

//������������� ������������
class Paladin : public Warrior, public Wizard
    //��������� ���������������� ����� ����������� ����� �������
{
public:
    Paladin()
    {
        name = "�������";
        health = 25;
        damage = 12;
        strenght = 27;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� � ����� ���������� - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void Create() override
    {
        cout << "�� ������� ��������" << endl;
        cout << "������� ��� ���������\t";
        cin >> name;
        GetInfo();
        CastSpell();
        GetWeapons();
    }
};
