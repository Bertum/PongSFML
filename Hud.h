#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"
#include <string>

class Hud
{
public:
	Hud(sf::RenderWindow* renderWindow);
	void Update();
	int scoreLeft;
	int scoreRight;
private:
	sf::Text leftScoreText;
	sf::Text rightScoreText;
	sf::RenderWindow* window;
	sf::Font font;
	void LoadText(sf::Text* text, float postX, float posY, sf::String string);
};
