#include <iostream>
#include <string>
#include <chrono>
#include "Rig.h"
#include "RigGas.h"
#include "RigOil.h"
#include "RigWater.h"
#include "Field.h"


using namespace std;

void create_rig(Field* field)
{
    cout << "Введите тип скважены (1-нефть, 2-газ, 3-вода): ";
    int index;
    cin >> index;
    cout << "Введите название скважены: ";
    string name;
    cin >> name;
    cout << "Введите мощность скважены: ";
    int power;
    cin >> power;

    Rig* rig = nullptr;

    switch (index)
    {
    case 1:
        rig = new RigOil(power, name);
        break;
    case 2:
        rig = new RigGas(power, name);
        break;
    case 3:
        rig = new RigWater(power, name);
        break;
    default:
        cerr << "Выбран некорректный индекс скважены!" << endl;
    }

    if (rig != nullptr)
    {
        field->add_rig(rig);
    }
}

void print_rigs(Field* field)
{
    int i = 0;

    if (field->get_rigs().size() > 0)
    {
        for (auto rig : field->get_rigs())
        {
            string status = "";
            if (rig->get_status())
            {
                status = "включен";
            }
            else
            {
                status = "выключен";
            }

            cout << i << ") Имя: " << rig->get_name() << ", статус: " << status
                << ", объем: " << rig->get_valume() << ", мощность: " << rig->get_power();
            cout << endl;
            i++;
        }
    }
    else
    {
        cout << "Нет скважен" << endl;
    }
}

Rig* get_rig(Field* field)
{
    cout << "Введите номер скважены: ";
    int index;
    cin >> index;

    return field->get_rig(index);
}

void change_rig_power(Field* field)
{
    Rig* rig = get_rig(field);
    cout << "Введите новую мощность скважены: ";
    int power;
    cin >> power;
    rig->change_power(power);
}

void change_rig_status(Field* field)
{
    Rig* rig = get_rig(field);
    rig->change_status();
}

void delete_rig(Field* field)
{
    cout << "Введите номер скважены: ";
    int index;
    cin >> index;
    field->delete_rig(index);
}

void do_cycle(Field* field)
{
    field->punp_rigs();
}

void print_field_valume(Field* field)
{
    int oil = field->get_oil();
    int gas = field->get_gas();
    int water = field->get_water();
    int max_valume = field->get_max_valume();

    int free_valume = max_valume - oil - gas - water;
    cout << " Нефти: " << oil << ", газа: " << gas
        << ", воды: " << water << ", пустого пространства: " << free_valume << endl;
}

void print_menu()
{
    cout << "Выберите действие:" << endl;
    cout << "1. Добавить скважену" << endl;
    cout << "2. Вывести все скважены" << endl;
    cout << "3. Изменить мощность скважены" << endl;
    cout << "4. Включить/выключить скважену" << endl;
    cout << "5. Удалить скважену" << endl;
    cout << "6. Совершить цикл" << endl;
    cout << "7. Вывести содержание месторождения" << endl;
    cout << "10. Выход" << endl;
}

int main()
{
    system("chcp 1251 > nul");
    setlocale(0, "");
    cout << "Введите объем нефти: ";
    int oil;
    cin >> oil;
    cout << "Введите объем газа: ";
    int gas;
    cin >> gas;
    cout << "Введите объем воды: ";
    int water;
    cin >> water;

    Field* field = new Field(oil, gas, water);

    bool end = false;
    int doing;
    while (!end)
    {
        cout << "\n";
        print_menu();
        cout << "\n";
        cout << "Введите номер: ";
        cin >> doing;
        switch (doing)
        {
        case 1:
            create_rig(field);
            break;
        case 2:
            print_rigs(field);
            break;
        case 3:
            change_rig_power(field);
            break;
        case 4:
            change_rig_status(field);
            break;
        case 5:
            delete_rig(field);
            break;
        case 6:
            do_cycle(field);
            break;
        case 7:
            print_field_valume(field);
            break;
        case 10:
            end = true;
            delete field;
            break;
        default:
            cerr << "Выбран некорректный номер действия!" << endl;
        }
    }
    return 0;
}
