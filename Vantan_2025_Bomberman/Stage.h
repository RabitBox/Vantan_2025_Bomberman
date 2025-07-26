#pragma once
#include "Cell.h"

using namespace Grid;

class Stage
{
private:
	/// @brief ステージの構成データ
	std::vector<Cell> _grids;

	/// @brief 配列の横幅
	const int WIDTH;

	/// @brief 配列の立幅
	const int HEIGHT;

public:
	Stage(int x, int y);
	virtual ~Stage();

	void BuildStage();

	void draw();
	void update();

	bool tryMoveTo(int x, int y);
	void swapObj(int fromX, int fromY, int toX, int toY);
};

