#pragma once
#include "BackgroundObject.h"


class BackgroundManager
{
public:
	BackgroundManager();
	~BackgroundManager();

	void Add(std::string name, BackgroundObject* gameObject);
	void Remove(std::string name);
	int GetObjectCount() const;
	BackgroundObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& renderWindow);
	void UpdateAll(float& elapsedTime, sf::RenderWindow& rw);

private:
	std::map<std::string, BackgroundObject*> _gameObjects;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, BackgroundObject*>& p) const
		{
			delete p.second;
		}
	};
};