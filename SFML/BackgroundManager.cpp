#include "stdafx.h"
#include "BackgroundManager.h"
#include "Game.h"

BackgroundManager::BackgroundManager()
{
}

BackgroundManager::~BackgroundManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void BackgroundManager::Add(std::string name, BackgroundObject* gameObject)
{
	_gameObjects.insert(std::pair<std::string, BackgroundObject*>(name, gameObject));
}

void BackgroundManager::Remove(std::string name)
{
	std::map<std::string, BackgroundObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

BackgroundObject* BackgroundManager::Get(std::string name) const
{
	std::map<std::string, BackgroundObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end())
		return NULL;
	return results->second;

}

int BackgroundManager::GetObjectCount() const
{
	return _gameObjects.size();
}


void BackgroundManager::DrawAll(sf::RenderWindow& renderWindow)
{
	std::map<std::string, BackgroundObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->Draw(renderWindow);
		itr++;

	}
}
void BackgroundManager::UpdateAll(float& elapsedTime, sf::RenderWindow& rw)
{
	std::map<std::string, BackgroundObject*>::const_iterator itr = _gameObjects.begin();

	while (itr != _gameObjects.end())
	{
		itr->second->Update(elapsedTime, rw);
		itr++;
	}

}