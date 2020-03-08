#include "pos.h"

int offset[4][2] = { {-1, 0},
					{0, 1},
					{1, 0},
					{0, -1} };
/* 북, 동, 남, 서 방향으로 한 칸 이동할 때
	x-좌표와 y-좌표의 변화량 */

Position move_to(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][0];
	next.y = pos.y + offset[dir][1];
	return next;
}