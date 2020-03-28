#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

class Ball
{
public:
	Ball(sf::RenderWindow* screen);
	void Update(float deltaTime);
private:
	sf::CircleShape* circleShape;
	sf::RenderWindow* window;
	void Move(float deltaTime);
	void CheckOutOfScreen();
	void ResetBall();
};
