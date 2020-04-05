#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "DEFINITIONS.h"
#include "Paddle.h"
#include "Hud.h"

class Ball
{
public:
	Ball(sf::RenderWindow* screen);
	void Update(float deltaTime, Paddle* paddleLeft, Paddle* paddleRight, Hud* hud);
	void ResetBall();
private:
	sf::CircleShape* circleShape;
	sf::RenderWindow* window;
	sf::Vector2f speed;
	sf::SoundBuffer pongSoundBuffer;
	sf::Sound pongsound;
	sf::SoundBuffer goalSoundBuffer;
	sf::Sound goalSound;
	void Move(float deltaTime);
	void CheckOutOfScreen(Hud* hud);
	void CheckCollisions(Paddle* paddle);
};
