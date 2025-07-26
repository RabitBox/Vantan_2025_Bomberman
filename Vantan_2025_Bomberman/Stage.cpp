#include "stdafx.h"
#include "Stage.h"
#include "Obstacle.h"
#include "Player.h"

enum CellType {
	WALL = 1,
	PLAYER = 10,
};

Stage::Stage(int x, int y)
	: WIDTH	(3 + (2 * x))
	, HEIGHT(3 + (2 * y))
{
	_grids.resize(WIDTH * HEIGHT);

	bool isPlayerPlaced = false;

	for (int dx = 0; dx < WIDTH; dx++) {
		for (int dy = 0; dy < HEIGHT; dy++) {
			int index = dy * WIDTH + dx;
			_grids[index].X = dx;
			_grids[index].Y = dy;

			if (dx == 0
				|| dy == 0
				|| dx == (WIDTH - 1)
				|| dy == (HEIGHT - 1)) {
				_grids[index].Type = CellType::WALL;
				continue;
			}
			else {
				if (dx % 2 == 0 && dy % 2 == 0) {
					_grids[index].Type = CellType::WALL;
				}
			}

			if (isPlayerPlaced == false) {
				isPlayerPlaced = true;
				_grids[index].Type = CellType::PLAYER;
			}
		}
	}
}

Stage::~Stage() {}

void Stage::BuildStage() {
	for (auto& obj : _grids) {
		switch (obj.Type) {
		case CellType::WALL:
			obj.Obj = Obstacle::create(obj);
			break;

		case CellType::PLAYER:
			obj.Obj = Player::create(obj);
			obj.Obj->setOwner( this );
			break;

		default:
			break;
		}
	}
}

void Stage::draw() {
	for (auto& obj : _grids) {
		if (obj.Obj) {
			obj.Obj->draw();
		}
	}
}

void Stage::update() {
	for (auto& obj : _grids) {
		if (obj.Obj) {
			obj.Obj->update();
		}
	}
}

bool Stage::tryMoveTo(int x, int y)
{
	auto index = x + y * WIDTH;
	if (_grids[index].Obj == nullptr) {
		return true;
	}
	return false;
}

void Stage::swapObj(int fromX, int fromY, int toX, int toY)
{
	auto from = fromX + fromY * WIDTH;
	auto to = toX + toY * WIDTH;

	_grids[to].Obj = _grids[from].Obj;
	_grids[from].Obj = nullptr;
}
