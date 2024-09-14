#include <iostream>
#include <menu.hpp>
#include <simulation.hpp>

Menu::Menu(Simulation* simulation) 
: selectedIndex(0), simulation(simulation) {
    InitializeMenuItems();
}

void BasicGlider(Simulation* simulation) {
    simulation->SetCellValue(1, 2, 1);
    simulation->SetCellValue(2, 3, 1);
    simulation->SetCellValue(3, 1, 1);
    simulation->SetCellValue(3, 2, 1);
    simulation->SetCellValue(3, 3, 1);
}

void Action2(Simulation* simulation) {
    printf("Option 2 selected!\n");
}

void Action3(Simulation* simulation) {
    printf("Option 3 selected!\n");
}

void Menu::InitializeMenuItems() {
    menuItems.emplace_back(MenuItem{"Basic Glider", BasicGlider});
    menuItems.emplace_back(MenuItem{"Option 2", Action2});
    menuItems.emplace_back(MenuItem{"Option 3", Action3});
}

void Menu::Update(Simulation* simulation) {
    if (IsKeyPressed(KEY_DOWN)) {
        selectedIndex++;
        if (selectedIndex >= menuItems.size()) {
            selectedIndex = 0;
        }
    }
    if (IsKeyPressed(KEY_UP)) {
        selectedIndex--;
        if (selectedIndex < 0) {
            selectedIndex = menuItems.size() - 1;
        }
    }
    if (IsKeyPressed(KEY_ENTER)) {
        menuItems[selectedIndex].action(simulation);
    }
}

void Menu::Draw() {
    int menuWidth = 200;
    int menuHeight = menuItems.size() * 30 + 20;

    int x = 10;
    int y = 10;

    DrawRectangle(x, y, menuWidth, menuHeight, LIGHTGRAY);

    for (int i = 0; i < menuItems.size(); ++i) {
        Color color = (i == selectedIndex) ? DARKGRAY : BLACK;
        DrawText(menuItems[i].text.c_str(), 
                 x + (menuWidth / 2) - (MeasureText(menuItems[i].text.c_str(), 20) / 2), 
                 y + 10 + i * 30,
                 20, color);
    }
}
