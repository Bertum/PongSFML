#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"
#include "Ball.h"
#include "Paddle.h"

class Game
{
public:
	Game();
private:
	void Run();
	sf::RenderWindow window;
	Ball* ball;
	Paddle* paddleLeft;
	Paddle* paddleRight;
	sf::Clock clock;
};
