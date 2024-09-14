#pragma once

#include <raylib.h>
#include <string>
#include <vector>

class Menu {
public:
    Menu(); // Constructor to initialize menu items
    void Update();
    void Draw();

private:
    struct MenuItem {
        std::string text;
        void (*action)();
    };

    std::vector<MenuItem> menuItems;
    int selectedIndex;

    void InitializeMenuItems(); // Method to initialize menu items
};
