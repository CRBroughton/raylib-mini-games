#pragma once

#include <raylib.h>
#include <string>
#include <vector>
#include "simulation.hpp"

class Menu {
public:
    Menu(Simulation* simulation);
    void Update(Simulation* simulation);
    void Draw();
    bool show = false;

private:
    struct MenuItem {
    std::string text;
    void (*action)(Simulation* simulation);
    MenuItem(std::string text, void (*action)(Simulation* simulation)) : 
        text(text), action(action) {}
    };

    std::vector<MenuItem> menuItems;
    int selectedIndex;
    Simulation* simulation;

    void InitializeMenuItems();
};
