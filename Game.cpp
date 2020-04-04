#include "Game.h"

Game::Game() {
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
	paddleLeft = new Paddle(&window, 50, sf::Keyboard::W, sf::Keyboard::S);
	paddleRight = new Paddle(&window, SCREEN_WIDTH - 50, sf::Keyboard::Up, sf::Keyboard::Down);
	ball = new Ball(&window);
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
			paddleLeft->Update(deltaTime);
			paddleRight->Update(deltaTime);
			ball->Update(deltaTime, paddleLeft, paddleRight);
			window.display();
		}
	}
}
