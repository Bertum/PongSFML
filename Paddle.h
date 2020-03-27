#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

class Paddle
{
public:
	Paddle(sf::RenderWindow* renderWindow, float posX);
	void Update(float deltaTime);
private:
	sf::RenderWindow* window;
	sf::RectangleShape* rectShape;
};
