#include <iostream>
#include <menu.hpp>

Menu::Menu() : selectedIndex(0) {
    InitializeMenuItems();
}

void Action1() {
    printf("Option 1 selected!\n");
}

void Action2() {
    printf("Option 2 selected!\n");
}

void Action3() {
    printf("Option 3 selected!\n");
}
void Menu::InitializeMenuItems() {
    menuItems.emplace_back(MenuItem{"Option 1", Action1});
    menuItems.emplace_back(MenuItem{"Option 2", Action2});
    menuItems.emplace_back(MenuItem{"Option 3", Action3});
}

void Menu::Update() {
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
        menuItems[selectedIndex].action();
    }
}

void Menu::Draw() {
    int menuWidth = 100;
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
