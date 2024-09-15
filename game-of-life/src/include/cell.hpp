#pragma once

class Cell {
    public:
        Cell();
        bool isAlive();
        void setAlive(bool alive);
    private:
        bool alive = false;
};