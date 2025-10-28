
#pragma once
#include <iostream>

using namespace std;

class Npc
{
protected: //����������� 0 ���������� (���� ������ ������ ������ �������� � ����������)
           //�� ��� ��� �� ���� ������ � �������� ������ ���������

    string name{ "��������" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
   
public:    //��������� ����������� ������ (������������ ����� ����� � ����� �����)
   
    virtual void GetInfo() //����� ������
    {
        cout << "��� - " << name << endl;
        cout << "�������� - " << health << endl;
        cout << "���� - " << damage << endl;
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