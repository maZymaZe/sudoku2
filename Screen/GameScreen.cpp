#include "Screen/GameScreen.h"

#include <SFML/Graphics.hpp>
#include <memory>

#include "Game/Game.h"
#include "Screen/GameOverScreen.h"

using namespace Sudoku;

sf::Texture gamescreen;
GameScreen::GameScreen() :blank(Game::difficulty){
    gamescreen.loadFromFile("Resource/gms.png");
    gameScreen.setTexture(gamescreen);
    gameScreen.setPosition({0,0});
}

void GameScreen::handleInput(sf::RenderWindow& window) {
    blank.handleInput(window);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
}

void GameScreen::render(sf::RenderWindow& window) {
    window.draw(gameScreen);
    blank.render(window);
}
