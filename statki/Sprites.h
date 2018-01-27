#pragma once
#include <SFML\Graphics.hpp>
class Sprites
{
public:
	Sprites();
	sf::Sprite trafionySprite;
	sf::Sprite pudloSprite;
	sf::Sprite statek1Sprite;
	sf::Sprite statek2Sprite;
	sf::Sprite statek3Sprite;
	sf::Sprite statek4Sprite;
	sf::Sprite poleSprite;
	sf::Sprite planszaSprite;
	sf::Sprite przyciskSprite;

	~Sprites();
private:
	sf::Texture trafionyTexture;
	sf::Texture pudloTexture;
	sf::Texture statek1Texture;
	sf::Texture statek2Texture;
	sf::Texture statek3Texture;
	sf::Texture statek4Texture;
	sf::Texture poleTexture;
	sf::Texture planszaTexture;
	sf::Texture przyciskTexture;
};

