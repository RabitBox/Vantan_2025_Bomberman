#pragma once

namespace Grid
{
	class GameObject
	{
	public:
		GameObject() {}
		virtual ~GameObject() {}

		virtual void draw() = 0;
	};
}
