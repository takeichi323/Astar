#include "Aster.h"
#include <iostream>
#include <vector>
#include <random>
#include <queue>

const char WALL_CHAR = ' ';   //壁
const char EMPTY_CHAR = '□'; //道
const char PATH_CHAR = '*';   //経路用文字


//ノード用構造体
struct Node {
    Point point;
    int f, g, h;
};

// ヒューリスティック関数：マンハッタン距離を使用
int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}


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
            // ランダムに"□"か空白を選択
            map[i][j] = (dis(gen) == 0) ? WALL_CHAR : EMPTY_CHAR;
        }
    }
}

std::vector<Point> Aster::findPath(Point start, Point end) {
    // オープンリストとクローズドリスト
    std::priority_queue<Node> openList;
    std::vector<std::vector<Node>> closedList(rows, std::vector<Node>(cols));

    // 始点ノードをオープンリストに追加
    openList.push({ start, 0, 0, 0 });

    // 移動方向の定義
    std::vector<Point> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    while (!openList.empty()) {
        // オープンリストから最小のf値を持つノードを取得
        Node current = openList.top();
        openList.pop();

        // 終点に到達した場合、経路を返す
        if (current.point.x == end.x && current.point.y == end.y) {
            std::vector<Point> path;
            while (!(current.point.x == start.x && current.point.y == start.y)) {
                path.push_back(current.point);
                current = closedList[current.point.x][current.point.y];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        // クローズドリストに追加
        closedList[current.point.x][current.point.y] = current;

        // 隣接するセルに移動
        for (const auto& dir : directions) {
            Point neighbor = { current.point.x + dir.x, current.point.y + dir.y };
            // グリッド外や壁は無視
            if (neighbor.x < 0 || neighbor.x >= rows ||
                neighbor.y < 0 || neighbor.y >= cols ||
                map[neighbor.x][neighbor.y] == WALL_CHAR ||
                closedList[neighbor.x][neighbor.y].point.x != -1)
                continue;

            // 隣接ノードのf、g、h値を計算
            int g = current.g + 1;
            int h = heuristic(neighbor, end);
            int f = g + h;

            // オープンリストまたはクローズドリストにある同じノードよりも優れた経路が見つかれば、更新
            openList.push({ neighbor, f, g, h });
        }
    }

    // 経路が見つからなかった場合、空の経路を返す
    return {};
}