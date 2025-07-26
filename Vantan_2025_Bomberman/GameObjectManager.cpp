#include "stdafx.h"
#include "GameObjectManager.h"

GameObjectManager* GameObjectManager::_instance = nullptr;

std::vector<std::shared_ptr<GameObject>>& GameObjectManager::getObjects() {
	return _objectList;
}

void GameObjectManager::add(std::shared_ptr<GameObject> obj) {
	_objectList.push_back( obj );
}

void GameObjectManager::clear() {
	_objectList.clear();
}

void GameObjectManager::update() {
	for (auto& obj : _objectList) {
		obj->update();
	}
}

void GameObjectManager::draw() {
	for (auto& obj : _objectList) {
		obj->draw();
	}
}
