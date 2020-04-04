#include "Ball.h"

Ball::Ball(sf::RenderWindow* renderWindow) : window(renderWindow) {
	circleShape = new sf::CircleShape(10);
	circleShape->setOrigin(circleShape->getRadius(), circleShape->getRadius());
	speed.x = 100;
	speed.y = 50;
	ResetBall();
}

void Ball::Update(float deltaTime, Paddle* paddleLeft, Paddle* paddleRight) {
	window->draw(*circleShape);
	Move(deltaTime);
	CheckCollisions(paddleLeft);
	CheckCollisions(paddleRight);
	CheckOutOfScreen();
}

void Ball::Move(float deltaTime) {
	circleShape->move(deltaTime * speed.x, deltaTime * speed.y);
}

void Ball::CheckOutOfScreen() {
	if (circleShape->getPosition().x - circleShape->getRadius() < 0.f)
	{
		//Sum points right player
		ResetBall();
	}
	if (circleShape->getPosition().x + circleShape->getRadius() > SCREEN_WIDTH)
	{
		//Sum points left player
		ResetBall();
	}
}

void Ball::ResetBall() {
	circleShape->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void Ball::CheckCollisions(Paddle* paddle) {
	if (this->circleShape->getGlobalBounds().intersects(paddle->rectShape->getGlobalBounds()))
		speed.x *= -1;

	if (this->circleShape->getPosition().y - this->circleShape->getRadius() <= 0 && speed.y < 0)
		speed.y *= -1;
	if (this->circleShape->getPosition().y + this->circleShape->getRadius() >= SCREEN_HEIGHT && speed.y > 0)
		speed.y *= -1;
}
