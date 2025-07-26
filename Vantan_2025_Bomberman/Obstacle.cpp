#include "stdafx.h"
#include "Obstacle.h"

namespace {
	constexpr int SIZE = 80;
}

namespace Grid
{
	Obstacle::Obstacle()
		: _type(Type::Wall)
	{}

	Obstacle::Obstacle(int type, int x, int y) {
		switch (type) {
		case 1:
			_type = Type::Wall;
			break;

		default:
			_type = Type::Brock;
			break;
		}
		_rect = Rect{ x * SIZE, y * SIZE, SIZE, SIZE };
	}

	Obstacle::~Obstacle() {}

	std::shared_ptr<Obstacle> Obstacle::create(Cell& cell)
	{
		auto obj = std::make_shared<Obstacle>(cell.Type, cell.X, cell.Y);
		return obj;
	}

	void Obstacle::draw() {
		_rect.draw();
	}

	void Obstacle::update() {}
}
