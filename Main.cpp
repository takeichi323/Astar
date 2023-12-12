#include<vector>

struct ASNode {
	int x, y;//位置座標
	int cost, heurccost; //実際のコスト,ヒューリスティックコスト
};