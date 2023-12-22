#include "Aster.h"
#include <iostream>
#include <vector>
#include <random>

const char WALL_CHAR = ' ';
const char EMPTY_CHAR = 'Å†';

Aster::Aster(int rows, int cols) : rows(rows), cols(cols), map(rows, std::vector<char>(cols, EMPTY_CHAR)) {
    generateRandomWalls();
}

void Aster::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void Aster::generateRandomWalls() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // ÉâÉìÉ_ÉÄÇ…"Å†"Ç©ãÛîíÇëIë
            map[i][j] = (dis(gen) == 0) ? WALL_CHAR : EMPTY_CHAR;
        }
    }
}