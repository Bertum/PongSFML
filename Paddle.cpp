#include "Paddle.h"

Paddle::Paddle(sf::RenderWindow* renderWindow, float posX) : window(renderWindow) {
	rectShape = new sf::RectangleShape(sf::Vector2f(20, SCREEN_HEIGHT / 3));
	rectShape->setOrigin(rectShape->getGlobalBounds().width / 2, rectShape->getGlobalBounds().height / 2);
	rectShape->setPosition(posX, SCREEN_HEIGHT / 2);
}

void Paddle::Update(float deltaTime) {
	window->draw(*rectShape);
}
