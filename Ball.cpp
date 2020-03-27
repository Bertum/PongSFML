#include "Ball.h"

Ball::Ball(sf::RenderWindow* renderWindow) : window(renderWindow) {
	circleShape = new sf::CircleShape(10);
	circleShape->setOrigin(circleShape->getRadius(), circleShape->getRadius());
	circleShape->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void Ball::Update(float deltaTime) {
	window->draw(*circleShape);
}
