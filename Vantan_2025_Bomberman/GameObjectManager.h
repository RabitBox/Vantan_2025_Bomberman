#pragma once
#include "GridGameObject.h"

using namespace Grid;

class GameObjectManager
{
private:
	GameObjectManager() = default;
	~GameObjectManager() = default;

	static GameObjectManager* _instance;

public:
	// 複製禁止
	GameObjectManager(const GameObjectManager&) = delete;
	GameObjectManager& operator=(const GameObjectManager&) = delete;
	GameObjectManager(GameObjectManager&&) = delete;
	GameObjectManager& operator=(GameObjectManager&&) = delete;

	static GameObjectManager& getInstance() {
		if (_instance == nullptr) {
			_instance = new GameObjectManager();
		}
		return *_instance;
	}

	static void dispose() {
		delete _instance;
		_instance = nullptr;
	}

private:
	std::vector<std::shared_ptr<GameObject>> _objectList;

public:
	std::vector<std::shared_ptr<GameObject>>& getObjects();

	void add(std::shared_ptr<GameObject> obj);
	void clear();

	void update();
	void draw();
};

