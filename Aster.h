#include <vector>

// 2次元座標を表す構造体
struct Point {
    int x, y;
};

// Asterクラスの宣言
class Aster {
public:
    Aster(int rows, int cols);
    void display() const;
    void generateRandomWalls();

    // A*アルゴリズムの宣言
    std::vector<Point> findPath(Point start, Point end);

private:
    int rows, cols;
    std::vector<std::vector<char>> map;
};


