#pragma once

class VisibleGameObject {
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();
	virtual void Load(sf::Texture& texture, std::string filename);
	virtual void Draw(sf::RenderWindow& window);
	virtual void Update(float elapsedTime, sf::RenderWindow& rw);

	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition() const;
	virtual bool IsLoaded() const;

protected:
	sf::Sprite& GetSprite();

private:
	sf::Sprite  _sprite;
	sf::Image _image;
	std::string _filename;
	bool _isLoaded;
};