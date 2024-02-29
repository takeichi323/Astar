#include <vector>

// Point �\���̂̒�`
struct Point {
    int x, y;
};

// Aster �N���X�̐錾
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

