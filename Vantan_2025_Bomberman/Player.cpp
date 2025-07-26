#include "stdafx.h"
#include "Player.h"
#include "Stage.h"

namespace {
	constexpr int SIZE = 80;
}

namespace Grid
{
	Player::Player()
		: _circle({ 0,0,0 })
		, x(0)
		, y(0)
		, _owner(nullptr)
	{
	}

	Player::~Player() {}

	std::shared_ptr<Player> Player::create(Cell& cell) {
		auto obj = std::make_shared<Player>();
		obj->updatePos(cell.X, cell.Y);
		return obj;
	}

	void Player::updatePos(int x, int y)
	{
		this->x = x;
		this->y = y;
		auto half = SIZE / 2;
		_circle = Circle(
			x * SIZE + half,
			y * SIZE + half,
			half * 0.8f
		);
	}

	void Player::draw() {
		_circle.draw();
	}

	void Player::update() {
		int tmpX = x;
		int tmpY = y;
		if (KeyLeft.down()) {
			tmpX -= 1;
		}
		else if (KeyRight.down()) {
			tmpX += 1;
		}
		else if (KeyUp.down()) {
			tmpY -= 1;
		}
		else if (KeyDown.down()) {
			tmpY += 1;
		}

		if (_owner && _owner->tryMoveTo(tmpX, tmpY)) {
			updatePos(tmpX, tmpY);
		}
	}

	void Player::setOwner(Stage* owner) {
		_owner = owner;
	}
}
