#include <vector>

class Aster {
public:
    Aster(int rows, int cols);

    void display() const;

private:
    int rows;
    int cols;
    std::vector<std::vector<char>> map;

    void generateRandomWalls();
};