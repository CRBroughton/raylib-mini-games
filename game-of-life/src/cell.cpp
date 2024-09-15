#include "cell.hpp"

Cell::Cell() {}

bool Cell::isAlive() {
    return alive;
}

void Cell::setAlive(bool alive) {
    this->alive = alive;
}