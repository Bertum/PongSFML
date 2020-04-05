#include "Game.h"

Game::Game() {
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
	leftPaddle = new Paddle(&window, 50, sf::Keyboard::W, sf::Keyboard::S);
	rightPaddle = new Paddle(&window, SCREEN_WIDTH - 50, sf::Keyboard::Up, sf::Keyboard::Down);
	ball = new Ball(&window);
	hud = new Hud(&window);
	gameFinished = false;
	Run();
}

void Game::Run() {
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		float deltaTime = dt.asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		if (!gameFinished) {
			leftPaddle->Update(deltaTime);
			rightPaddle->Update(deltaTime);
			ball->Update(deltaTime, leftPaddle, rightPaddle, hud);
			CheckFinishCondition();
		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				hud->ResetScore();
				ball->ResetBall();
				leftPaddle->ResetPosition();
				rightPaddle->ResetPosition();
				gameFinished = false;
			}
		}
		hud->Update(gameFinished);
		window.display();
	}
}

void Game::CheckFinishCondition() {
	if (hud->leftScore >= 5 || hud->rightScore >= 5) {
		gameFinished = true;
		hud->CreateWinnerText();
	}
}
