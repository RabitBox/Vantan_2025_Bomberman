#pragma once
# include <Siv3D.hpp>
#include "GridGameObject.h"
#include "Cell.h"

namespace Grid
{
	class Player : public GameObject
	{
		//class Stage;

	private:
		Circle _circle;
		Stage* _owner;

	public:
		int x;
		int y;

	public:
		Player();
		virtual ~Player();

		static std::shared_ptr<Player> create(Cell& cell);

		void updatePos(int x, int y);

	public:
		void draw() override;
		void update() override;

		void setOwner(Stage* owner) override;
	};
}

