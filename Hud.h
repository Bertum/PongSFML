#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"
#include <string>

class Hud
{
public:
	Hud(sf::RenderWindow* renderWindow);
	void Update(bool gameFinished);
	void ResetScore();
	void CreateWinnerText();
	int leftScore;
	int rightScore;
private:
	sf::Text leftScoreText;
	sf::Text rightScoreText;
	sf::Text winnerText;
	sf::Text playAgainText;
	sf::RenderWindow* window;
	sf::Font font;
	void LoadText(sf::Text* text, float postX, float posY, sf::String string);
};
