#include "Aster.h"
#include <iostream>
#include <vector>
#include <random>
#include <queue>

const char WALL_CHAR = ' ';   //��
const char EMPTY_CHAR = '��'; //��
const char PATH_CHAR = '*';   //�o�H�p����


//�m�[�h�p�\����
struct Node {
    Point point;
    int f, g, h;
};

// �q���[���X�e�B�b�N�֐��F�}���n�b�^���������g�p
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
            // �����_����"��"���󔒂�I��
            map[i][j] = (dis(gen) == 0) ? WALL_CHAR : EMPTY_CHAR;
        }
    }
}

std::vector<Point> Aster::findPath(Point start, Point end) {
    // �I�[�v�����X�g�ƃN���[�Y�h���X�g
    std::priority_queue<Node> openList;
    std::vector<std::vector<Node>> closedList(rows, std::vector<Node>(cols));

    // �n�_�m�[�h���I�[�v�����X�g�ɒǉ�
    openList.push({ start, 0, 0, 0 });

    // �ړ������̒�`
    std::vector<Point> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    while (!openList.empty()) {
        // �I�[�v�����X�g����ŏ���f�l�����m�[�h���擾
        Node current = openList.top();
        openList.pop();

        // �I�_�ɓ��B�����ꍇ�A�o�H��Ԃ�
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

        // �N���[�Y�h���X�g�ɒǉ�
        closedList[current.point.x][current.point.y] = current;

        // �אڂ���Z���Ɉړ�
        for (const auto& dir : directions) {
            Point neighbor = { current.point.x + dir.x, current.point.y + dir.y };
            // �O���b�h�O��ǂ͖���
            if (neighbor.x < 0 || neighbor.x >= rows ||
                neighbor.y < 0 || neighbor.y >= cols ||
                map[neighbor.x][neighbor.y] == WALL_CHAR ||
                closedList[neighbor.x][neighbor.y].point.x != -1)
                continue;

            // �אڃm�[�h��f�Ag�Ah�l���v�Z
            int g = current.g + 1;
            int h = heuristic(neighbor, end);
            int f = g + h;

            // �I�[�v�����X�g�܂��̓N���[�Y�h���X�g�ɂ��铯���m�[�h�����D�ꂽ�o�H��������΁A�X�V
            openList.push({ neighbor, f, g, h });
        }
    }

    // �o�H��������Ȃ������ꍇ�A��̌o�H��Ԃ�
    return {};
}