#include "Ball.h"

Ball::Ball(sf::RenderWindow* renderWindow) : window(renderWindow) {
	circleShape = new sf::CircleShape(10);
	circleShape->setOrigin(circleShape->getRadius(), circleShape->getRadius());
	speed.x = 200;
	speed.y = 100;
	pongSoundBuffer.loadFromFile(PONG_SOUND_PATH);
	pongsound.setBuffer(pongSoundBuffer);
	goalSoundBuffer.loadFromFile(GOAL_SOUND_PATH);
	goalSound.setBuffer(goalSoundBuffer);
	ResetBall();
}

void Ball::Update(float deltaTime, Paddle* paddleLeft, Paddle* paddleRight, Hud* hud) {
	window->draw(*circleShape);
	Move(deltaTime);
	CheckCollisions(paddleLeft);
	CheckCollisions(paddleRight);
	CheckOutOfScreen(hud);
}

void Ball::Move(float deltaTime) {
	circleShape->move(deltaTime * speed.x, deltaTime * speed.y);
}

void Ball::CheckOutOfScreen(Hud* hud) {
	if (circleShape->getPosition().x - circleShape->getRadius() < 0.f)
	{
		hud->rightScore++;
		goalSound.play();
		ResetBall();
	}
	if (circleShape->getPosition().x + circleShape->getRadius() > SCREEN_WIDTH)
	{
		hud->leftScore++;
		goalSound.play();
		ResetBall();
	}
}

void Ball::ResetBall() {
	speed.x = 200;
	speed.y = 100;
	circleShape->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void Ball::CheckCollisions(Paddle* paddle) {
	if (this->circleShape->getGlobalBounds().intersects(paddle->rectShape->getGlobalBounds())) {
		if (speed.x < 600 && speed.x > -600)
			speed.x *= -1.5;
		else
			speed.x *= -1;
		pongsound.play();
	}
	if (this->circleShape->getPosition().y - this->circleShape->getRadius() <= 0 && speed.y < 0) {
		speed.y *= -1;
		pongsound.play();
	}
	if (this->circleShape->getPosition().y + this->circleShape->getRadius() >= SCREEN_HEIGHT && speed.y > 0) {
		speed.y *= -1;
		pongsound.play();
	}
}
