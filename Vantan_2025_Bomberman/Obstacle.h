#pragma once
# include <Siv3D.hpp>
#include "GridGameObject.h"
#include "Cell.h"

namespace Grid
{
	/// @brief ブロッククラス
	class Obstacle : public GameObject
	{
	public:
		enum Type {
			Wall	= 0,
			Brock	= 1,
		};

	private:
		int _type;
		Rect _rect;

	public:
		Obstacle();
		Obstacle(int type, int x, int y);

	public:
		virtual ~Obstacle();

		static std::shared_ptr<Obstacle> create(Cell& cell);

		void draw() override;
		void update() override;
	};
}

