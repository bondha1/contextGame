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
    string name{ "добыча" };
    ValueQuality quality = ValueQuality::trash;
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
    Cloth(ValueQuality quality) : Treasure(quality) {}
    string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
    string site{ NULL };
    unsigned short armor{ 1 };

};

enum class CharacterType
{
    UNKNOW = 0,
    WARRIOR,
    WIZARD,
    PALADDIN
};

unique_ptr<Npc> CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::UNKNOW:
        return make_unique<Npc>();
        break;
    case CharacterType::WARRIOR:
        return make_unique<Warrior>();
        break;
    case CharacterType::WIZARD:
        return make_unique<Wizard>();
        break;
    case CharacterType::PALADDIN:
        return make_unique<Paladin>();
        break;
    default:
        invalid_argument("Неизвестный тип персонажа");
        break;
    }
}

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
};


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

    Player* player = new Player();

    cout << "Привет, путник\nПрисядь у костра и расскажи о себепТы впервые тут?\n\t1 - новый персонаж, \n\t ";
    if (TestChoise(2, "Наверно ты ошибся, повтори снова"))
    {
        cout << "Расскажи о своих навыках\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n";
        unique_ptr<Npc> character;
        switch (TestChoise(3, "Такого еще не было в наших краях\nНе мог бы ты повторить"))
        {
            case 1:
                character = CreateCharacter(CharacterType::WARRIOR);
                break;
            case 2:
                character = CreateCharacter(CharacterType::WIZARD);
                break;
            case 3:
                character = CreateCharacter(CharacterType::PALADDIN);
                break;
        }
        player->Create(move(character));

    }
    else
    {
        ifstream loadSystem("save.txt", ios::binary);
        if (!loadSystem.is_open())
        {
            cout << "";
        }
        else
        {

        }
    }






    return 0;
}




