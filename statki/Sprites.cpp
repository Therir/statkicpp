#include "stdafx.h"
#include "Sprites.h"


Sprites::Sprites()
{
	trafionyTexture.loadFromFile("img/statek_trafiony.png");
	pudloTexture.loadFromFile("img/pole_pudlo.png");
	statek1Texture.loadFromFile("img/statek1.png");
	statek2Texture.loadFromFile("img/statek2.png");
	statek3Texture.loadFromFile("img/statek3.png");
	statek4Texture.loadFromFile("img/statek4.png");

	przyciskTexture.loadFromFile("img/przycisk.png");
	poleTexture.loadFromFile("img/pole.png");
	planszaTexture.loadFromFile("img/grid.png");

	przyciskSprite.setTexture(przyciskTexture);
	trafionySprite.setTexture(trafionyTexture);
	pudloSprite.setTexture(pudloTexture);
	statek1Sprite.setTexture(statek1Texture);
	statek2Sprite.setTexture(statek2Texture);
	statek3Sprite.setTexture(statek3Texture);
	statek4Sprite.setTexture(statek4Texture);
	poleSprite.setTexture(poleTexture);
	planszaSprite.setTexture(planszaTexture);

}


Sprites::~Sprites()
{
}
