#include "Hud.h"

Hud::Hud(sf::RenderWindow* renderWindow) : window(renderWindow) {
	font.loadFromFile(FONT_PATH);
	LoadText(&leftScoreText, SCREEN_WIDTH / 2 - 50, 30, "0");
	LoadText(&rightScoreText, SCREEN_WIDTH - SCREEN_WIDTH / 2 + 50, 30, "0");
	LoadText(&playAgainText, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50, "Press enter to play again");
}

void Hud::Update(bool gameFinished) {
	leftScoreText.setString(std::to_string(leftScore));
	rightScoreText.setString(std::to_string(rightScore));
	window->draw(leftScoreText);
	window->draw(rightScoreText);
	if (gameFinished)
	{
		window->draw(winnerText);
		window->draw(playAgainText);
	}
}

void Hud::LoadText(sf::Text* text, float posX, float posY, sf::String string) {
	text->setFont(font);
	text->setString(string);
	text->setCharacterSize(25);
	text->setOrigin(text->getGlobalBounds().width / 2, text->getGlobalBounds().height / 2);
	text->setPosition(posX, posY);
}

void Hud::ResetScore() {
	leftScore = 0;
	rightScore = 0;
}

void Hud::CreateWinnerText() {
	sf::String winnerString;
	if (leftScore >= 5)
		winnerString = "Left player wins!";
	else if (rightScore >= 5)
		winnerString = "Right player wins!";
	LoadText(&winnerText, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, winnerString);
}
