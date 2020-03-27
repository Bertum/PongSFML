#include "Game.h"

Game::Game() {
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
	paddleLeft = new Paddle(&window, 50);
	paddleRight = new Paddle(&window, SCREEN_WIDTH - 50);
	ball = new Ball(&window);
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
		paddleLeft->Update(deltaTime);
		paddleRight->Update(deltaTime);
		ball->Update(deltaTime);
		window.display();
	}
}
