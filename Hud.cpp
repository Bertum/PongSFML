#include "Hud.h"

Hud::Hud(sf::RenderWindow* renderWindow) : window(renderWindow) {
	font.loadFromFile(FONT_PATH);
	LoadText(&leftScoreText, SCREEN_WIDTH / 2 - 50, 30, "0");
	LoadText(&rightScoreText, SCREEN_WIDTH - SCREEN_WIDTH / 2 + 50, 30, "0");
}

void Hud::Update() {
	leftScoreText.setString(std::to_string(scoreLeft));
	rightScoreText.setString(std::to_string(scoreRight));
	window->draw(leftScoreText);
	window->draw(rightScoreText);
}

void Hud::LoadText(sf::Text* text, float posX, float posY, sf::String string) {
	text->setFont(font);
	text->setString(string);
	text->setCharacterSize(25);
	text->setOrigin(text->getGlobalBounds().width / 2, text->getGlobalBounds().height / 2);
	text->setPosition(posX, posY);
}
