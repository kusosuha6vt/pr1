#include <ratio.h>
#include <clocale>
#include <iostream>
#include "menu.h"

int main() {
    std::setlocale(LC_ALL, "Russian");
    Ratio r;
    Menu mainMenu([&r]() {
        std::wcout << L"\tГлавное меню\n\n"
                      L"Текущая дробь: ";
        std::cout << r << "\n\n";
    });

    mainMenu.items.push_back({L"Вывести частное", [&r]() {
                                  std::wcout << L"Частное: " << r.getValue()
                                             << L'\n';
                                  Menu::awaitExit();
                              }});

    mainMenu.items.push_back({L"Изменить числитель", [&r]() {
                                  std::wcout << L"Введите числитель:\n";
                                  r.setNom(Menu::getInt(INT_MIN, INT_MAX));
                              }});
    mainMenu.items.push_back({L"Изменить знаменатель", [&r]() {
                                  std::wcout << L"Введите знаменатель:\n";
                                  r.setDenom(Menu::getInt(INT_MIN, INT_MAX));
                              }});

    mainMenu.items.push_back(
        {L"Вывести прямоугольник (числитель x знаменталь)", [&r]() {
             r.printRectangle();
             Menu::awaitExit();
         }});

    mainMenu.items.push_back({L"Сократить дробь", [&r]() { r = &r; }});

    mainMenu.items.push_back(
        {L"Вывести длину вектора из (0, 0) в (числ., знам.)", [&r]() {
             std::cout << "length=" << r.len() << "\n";
             Menu::awaitExit();
         }});

    mainMenu.items.push_back(
        {L"Поменять местами числитель, знаменатель", [&r]() { --r; }});

    mainMenu.items.push_back(
        {L"Стандартные методы", []() {
             {
                 std::wcout << L"Конструктор без параметров:\n";
                 Ratio r;
             }
             {
                 std::wcout << L"Конструктор с параметрами:\n";
                 Ratio r(22, 7);

                 std::wcout << L"Конструктор копирования:\n";
                 Ratio r2(r);

                 std::wcout << L"Присваивание:\n";
                 r2 = r;

                 std::wcout << L"Сравнение:\n";
                 std::wcout << L"r2==r: " << (r2 == r) << "\n\n";
                 Menu::awaitExit();
             }
         }});

    mainMenu.start();

    return 0;
}
