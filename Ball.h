#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"
#include "Paddle.h"

class Ball
{
public:
	Ball(sf::RenderWindow* screen);
	void Update(float deltaTime, Paddle* paddleLeft, Paddle* paddleRight);
private:
	sf::CircleShape* circleShape;
	sf::RenderWindow* window;
	sf::Vector2f speed;
	void Move(float deltaTime);
	void CheckOutOfScreen();
	void CheckCollisions(Paddle* paddle);
	void ResetBall();
};
