#include <iostream>
#include "windows.h"
#include "BaseClass.h"
#include "StartClasses.h"
#include "Evil.h"
#include "fstream"
using namespace std;

enum class ValueQuality
{
    trash, common, rare, mifical, legendary
};

struct Treasure // public
{
    string name{"добыча"};
    ValueQuality quality = ValueQuality ::trash;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::trash:
            cout << "качество плохое\n";
            break;
        case ValueQuality::common:
            cout << "качество среднее\n";
            break;
        case ValueQuality::rare:
            cout << "качество среднее\n";
            break;
        case ValueQuality::mifical:
            cout << "качество крутое\n";
            break;
        case ValueQuality::legendary:
            cout << "качество идеальное\n";
            break;
        default:
            break;
        }
    }

};


struct Cloth : Treasure
{
    Cloth(ValueQuality quality) : Treasure(quality){}
    string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
    string site{ NULL };
    unsigned short armor{ 1 };

};



//базовый класс - абстрактный (класс у которого все методы виртуальные)



int main()
{
    setlocale(LC_ALL, ".UTF-8");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Treasure treasure(ValueQuality::мифическое);
    //treasure.name = "древняя тарелка";
    //treasure.price = 30;
    //treasure.quality = treasure.valueQuality[3];
    //cout << treasure.name << '\n' << treasure.price << '\n' << treasure.quality << '\n';

    Cloth cloth(ValueQuality::mifical);
    cloth.armor = 10;
    cloth.site = cloth.valueSite[2];
    cloth.name = "шлем древнего друида";
    cloth.price = 50;
    cout << cloth.name << '\n' << cloth.price << '\n' << cloth.site << '\n' << cloth.armor << '\n';

    Warrior* warrior = new Warrior();
    Warrior* warrior2 = new Warrior();
    cout << (*warrior == *warrior2) << endl;

    Wizard* wizard = new Wizard();
    Paladin* paladin = new Paladin();
    Player* player = new Player();

    cout << "Привет, путник\nПрисядь у костра и расскажи о себе\n";
    cout << "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n";
    unsigned short choise = 1;
    cin >> choise;
    while (choise > 2 || choise < 1)
    {
        cout << "Наверное ты ошибся, повтори снова\n";
        cin >> choise;
    }
    /*
    unsigned short maxChoise = 3;
    unsigned short TestChoise(unsigned short maxChoise, string text);
    {
        unsigned short choise = 1;
        cin >> choise;
        while (choise > maxChoise || choise < 1)
        {
            cout << "Наверное ты ошибся, повтори снова\n";
            cin >> choise;
        }
        return choise;

       
    };

    */
    
    if (choise == 1)
    {
        cout << "Расскажи о своих навыках\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n";

        // тут уже будет вызвана ваша красивая функция
        cin >> choise;
        while (choise > 3 || choise < 1)
        {
            cout << "Такого еще не было в наших краях\nНе мог бы ты повторить\n";
            cin >> choise;
        }


        switch (choise)
        {
        case 1: {
            player->Create(warrior);
            delete wizard;
            wizard = nullptr;
            delete paladin;
            paladin = nullptr;
            break; }
        case 2: {
            player->Create(wizard);
            delete warrior;
            warrior = nullptr;
            delete paladin;
            paladin = nullptr;
            cout << " " << endl;
            break; }
        case 3: {
            player->Create(paladin);
            delete warrior;
            warrior = nullptr;
            delete wizard;
            wizard = nullptr;
            break; }
        }

    }

    else
    {
        player->Load(warrior);
    }

    cout << "сделаем остановку тут?\n\t1 - сохранить игру\n\t2 - продолжить\n";
    cin >> choise;
    if (choise == 1)
    {
        if (warrior != nullptr) player->Save(warrior);
        if (wizard != nullptr) player->Save(wizard);
        if (paladin != nullptr) player->Save(paladin);
    }



    return 0;
}

