#pragma once

class GameObject;

namespace Grid
{
	/// @brief グリッドの単位セル
	struct Cell
	{
	public:
		/// @brief セルの属性
		int Type;

		/// @brief セルに紐づくオブジェクト
		//std::unique_ptr<GameObject> Obj;
	};
}

