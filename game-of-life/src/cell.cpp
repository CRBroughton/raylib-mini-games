#include "cell.hpp"

bool Cell::isAlive() {
    return alive;
}

void Cell::setAlive(bool alive) {
    this->alive = alive;
}