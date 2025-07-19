#include "stdafx.h"
#include "Stage.h"
#include "Obstacle.h"

Stage::Stage(int x, int y)
	: WIDTH	(3 + (2 * x))
	, HEIGHT(3 + (2 * y))
{
	_grids.resize(WIDTH * HEIGHT);

	for (int dx = 0; dx < WIDTH; dx++) {
		for (int dy = 0; dy < HEIGHT; dy++) {
			int index = dy * WIDTH + dx;
			if (dx == 0
				|| dy == 0
				|| dx == (WIDTH - 1)
				|| dy == (HEIGHT - 1)) {
				_grids[index].Type = 1;
			}
			else {
				if (dx % 2 == 0 && dy % 2 == 0) {
					_grids[index].Type = 1;
				}
			}
		}
	}
}

Stage::~Stage() {}

void Stage::BuildStage() {
	for (auto& obj : _grids) {
		switch (obj.Type) {
		case 1:
			obj.Obj = Obstacle::create(obj.Type);
			break;

		default:
			break;
		}
	}
}
