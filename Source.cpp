#include <iostream>
#include "windows.h"
#include "BaseClass.h"
#include "StartClasses.h"

using namespace std;

//������������ �������:
// private - ���������, ��������� ������ � ��������� � �������
//           �� ��������� ������ ������
// protected - ����������, ����� ���������� �������� � ������
//        � ������ ����������, �� ��� ��� ������ ������������
//        � �������� ������ ���������
// public - ���������, �������������, ����� ������������ �����


//������� ����� - ����������� (����� � �������� ��� ������ �����������)



int main()
{
  setlocale(LC_ALL, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  Warrior* warrior = new Warrior();
  Warrior* warrior2 = new Warrior();
  cout << (*warrior == *warrior2) << endl;

  Wizard* wizard = new Wizard();
  Paladin* paladin = new Paladin();
  Player* player = new Player();

  cout << "������, ������\n������� � ������ � �������� � ����\n";
  cout << "�� ������� ���? (1 - ����� ��������, 2 - ���������)\n";
  unsigned short choise = 1;
  //������� ���������� ������� ��� �������� ������� ������
  cin >> choise;
  while (choise > 2 || choise < 1)
  {
    cout << "�������� �� ������, ������� �����\n";
    cin >> choise;
  }
  if (choise == 1)
  {
    cout << "�������� � ����� �������\n\t1 - ����\n\t2 - ���������\n\t3 - �������\n";
    
    // ��� ��� ����� ������� ���� �������� �������
    cin >> choise;
    while (choise > 3 || choise < 1)
    {
      cout << "������ ��� �� ���� � ����� �����\n�� ��� �� �� ���������\n";
      cin >> choise;
    }
    
    /*
    switch (choise)
    {
    case 1: {
      player->Create(&warrior);
      delete wizard;
      delete paladin;
      break; }
    case 2: {
      player->Create(&wizard);
      delete warrior;
      delete paladin;
      cout << " " << endl;
      break; }
    case 3: {
      player->Create(&paladin);
      delete warrior;
      delete wizard;
      break; }
    }
    */
    

  }



  


  return 0;
}
