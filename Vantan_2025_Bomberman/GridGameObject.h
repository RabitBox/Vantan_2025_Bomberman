#pragma once

class Stage;

namespace Grid
{
	class GameObject
	{
	public:
		GameObject() {}
		virtual ~GameObject() {}

		virtual void draw() = 0;
		virtual void update() = 0;

		virtual void setOwner(Stage* owner) {}
	};
}
