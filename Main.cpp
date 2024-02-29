#include "Aster.h"
#include <iostream>

int main() {
    // マップのサイズを定義
    int rows = 10;
    int cols = 10;

    // Aster クラスのインスタンスを作成
    Aster aster(rows, cols);

    // マップ表示
    std::cout << "Initial Map:\n";
    aster.display();

    // 始点と終点を定義
    Point start = { 0, 0 };
    Point end = { rows - 1, cols - 1 };

    // パス探索
    std::vector<Point> path = aster.findPath(start, end);

    // パスが見つかった場合、経路を表示
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