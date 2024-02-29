#include <vector>

// Point 構造体の定義
struct Point {
    int x, y;
};

// Aster クラスの宣言
class Aster {
public:
    Aster(int rows, int cols);
    void display() const;
    std::vector<Point> findPath(Point start, Point end);

private:
    int rows, cols;
    std::vector<std::vector<char>> map;

    void generateRandomWalls();
};

