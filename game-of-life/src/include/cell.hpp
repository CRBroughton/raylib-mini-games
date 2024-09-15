#pragma once

class Cell {
    public:
        Cell();
        bool isAlive();
        void setAlive(bool alive);
        void decrementHealth() {
            this->health--;
        };
        void maxHealth() {
            this->health = 2;
        }
        int getHealth() {
            return this->health;
        }
        void resetHealth() {
            this->health = 0;
        }
    private:
        bool alive = false;
        int health;
};