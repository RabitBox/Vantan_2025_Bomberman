#include "stdafx.h"
#include "Obstacle.h"

namespace Grid
{
	Obstacle::Obstacle()
		: _type(Type::Wall)
	{}

	Obstacle::Obstacle(int type) {
		switch (type) {
		case 1:
			_type = Type::Wall;
			break;

		default:
			_type = Type::Brock;
			break;
		}
	}

	Obstacle::~Obstacle() {}

	std::shared_ptr<Obstacle> Obstacle::create(int type)
	{
		auto obj = std::make_shared<Obstacle>(type);
		return obj;
	}

	void Obstacle::draw() {

	}
}
