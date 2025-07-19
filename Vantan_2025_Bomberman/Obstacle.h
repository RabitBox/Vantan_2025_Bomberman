#pragma once
#include "GridGameObject.h"

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

	public:
		Obstacle();
		Obstacle(int type);

	public:
		virtual ~Obstacle();

		static std::shared_ptr<Obstacle> create(int type);

		void draw() override;
	};
}

