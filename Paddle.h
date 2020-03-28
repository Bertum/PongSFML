﻿#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

class Paddle
{
public:
	Paddle(sf::RenderWindow* renderWindow, float posX, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
	void Update(float deltaTime);
private:
	sf::RenderWindow* window;
	sf::RectangleShape* rectShape;
	sf::Keyboard::Key upKeyEnum;
	sf::Keyboard::Key downKeyEnum;
	float speed;
	void Move(float deltaTime);
};
