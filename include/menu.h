#ifndef MENU_H
#define MENU_H

#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct MenuItem {
    std::wstring name;
    std::function<void()> action;
};

struct Menu {
    Menu(std::function<void()> beforeStart, bool clr = true)
        : beforeStart{beforeStart}, clr{clr} {
    }

    void clearScreen() const {
        if (clr)
            system("cls");
    }

    static int getInt(int l, int r) {
        int res;
        std::string line;
        std::cout << "> ";
        std::getline(std::cin, line);
        try {
            res = std::stoi(line);
        } catch (...) {
            std::wcout << L"Попробуйте еще раз.\n";
            return getInt(l, r);
        }
        if (res < l || res > r) {
            std::wcout << L"Нужно число [" << l << L"; " << r << L"]\n";
            return getInt(l, r);
        }
        return res;
    }

    static void awaitExit() {
        Menu menu([]() {}, false);
        menu.start();
    }

    void start() const {
        while (true) {
            clearScreen();
            beforeStart();
            std::wcout << L"Выберите действие:\n";
            for (int i = 0; i < items.size(); ++i) {
                const MenuItem &item = items[i];
                std::wcout << std::setw(2) << (i + 1) << L". " << item.name
                           << L'\n';
            }
            std::wcout << L" 0. Выход\n\n";
            int res = getInt(0, items.size());
            if (res == 0) {
                return;
            }
            res--;
            clearScreen();
            items[res].action();
        }
    }

    std::vector<MenuItem> items;
    std::function<void()> beforeStart;
    bool clr;
};

#endif
