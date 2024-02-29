#include "Aster.h"
#include <iostream>

int main() {
    // �}�b�v�̃T�C�Y���`
    int rows = 10;
    int cols = 10;

    // Aster �N���X�̃C���X�^���X���쐬
    Aster aster(rows, cols);

    // �}�b�v�\��
    std::cout << "Initial Map:\n";
    aster.display();

    // �n�_�ƏI�_���`
    Point start = { 0, 0 };
    Point end = { rows - 1, cols - 1 };

    // �p�X�T��
    std::vector<Point> path = aster.findPath(start, end);

    // �p�X�����������ꍇ�A�o�H��\��
    if (!path.empty()) {
        std::cout << "\nPath Found:\n";
        for (const auto& point : path) {
            std::cout << "(" << point.x << ", " << point.y << ") ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "\nPath Not Found\n";
    }

    return 0;
}