#include "GameOverScreen.h"

#include <SFML/Graphics.hpp>
#include <memory>

#include "Game/Game.h"
#include "Screen/MenuScreen.h"

using namespace Sudoku;

sf::Mouse mmouse;
sf::Texture gameoverscreen;
GameOverScreen::GameOverScreen() {
    gameoverscreen.loadFromFile("Resource/gameoverscreen.png");
    game_over_screen.setTexture(gameoverscreen);
    game_over_screen.setPosition({0, 0});
}
void GameOverScreen::handleInput(sf::RenderWindow& window) {
    if (mmouse.isButtonPressed(mmouse.Left))
        Game::Screen = std::make_shared<MenuScreen>();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
}
void GameOverScreen::render(sf::RenderWindow& window) {
    window.draw(game_over_screen);
}