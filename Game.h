#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "DEFINITIONS.h"
#include "Ball.h"
#include "Paddle.h"
#include "Hud.h"

class Game
{
public:
	Game();
private:
	void Run();
	sf::RenderWindow window;
	Ball* ball;
	Paddle* leftPaddle;
	Paddle* rightPaddle;
	Hud* hud;
	sf::Clock clock;
	bool gameFinished;
	void CheckFinishCondition();
};
