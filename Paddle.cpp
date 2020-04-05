#include "Paddle.h"

Paddle::Paddle(sf::RenderWindow* renderWindow, float posX, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey) : window(renderWindow), upKeyEnum(upKey), downKeyEnum(downKey) {
	speed = 1000;
	rectShape = new sf::RectangleShape(sf::Vector2f(10, SCREEN_HEIGHT / 6));
	rectShape->setOrigin(rectShape->getGlobalBounds().width / 2, rectShape->getGlobalBounds().height / 2);
	rectShape->setPosition(posX, SCREEN_HEIGHT / 2);
	initialPosX = posX;
}

void Paddle::Update(float deltaTime) {
	Move(deltaTime);
	window->draw(*rectShape);
}

void Paddle::Move(float deltaTime) {
	if (sf::Keyboard::isKeyPressed(upKeyEnum) &&
		(rectShape->getPosition().y - rectShape->getSize().y / 2 > 5.f))
	{
		rectShape->move(0.f, -speed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(downKeyEnum) &&
		((rectShape->getPosition().y + rectShape->getSize().y / 2) < SCREEN_HEIGHT - 5))
	{
		rectShape->move(0.f, speed * deltaTime);
	}
}

void Paddle::ResetPosition() {
	rectShape->setPosition(initialPosX, SCREEN_HEIGHT / 2);
}
