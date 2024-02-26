#include <vector>

// 2�������W��\���\����
struct Point {
    int x, y;
};

// Aster�N���X�̐錾
class Aster {
public:
    Aster(int rows, int cols);
    void display() const;
    void generateRandomWalls();

    // A*�A���S���Y���̐錾
    std::vector<Point> findPath(Point start, Point end);

private:
    int rows, cols;
    std::vector<std::vector<char>> map;
};


