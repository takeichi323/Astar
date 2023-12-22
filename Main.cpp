#include "Aster.h"

int main() {
    // マップのサイズを指定
    int rows = 10;
    int cols = 10;

    // マップを生成
    Aster myMap(rows, cols);

    // マップを表示
    myMap.display();

    return 0;
}