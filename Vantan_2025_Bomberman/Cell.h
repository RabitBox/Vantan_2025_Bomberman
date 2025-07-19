#pragma once
#include "GridGameObject.h"

namespace Grid
{
	/// @brief グリッドの単位セル
	struct Cell
	{
	public:
		/// @brief セルの属性
		int Type;

		/// @brief セルに紐づくオブジェクト
		std::shared_ptr<GameObject> Obj;
	};
}

