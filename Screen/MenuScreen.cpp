#include "MenuScreen.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Game/Game.h"
#include "GameScreen.h"

using namespace Sudoku;

sf::Texture menu;

MenuScreen::MenuScreen() {
    menu.loadFromFile("Resource/menu.png");
    Menu.setTexture(menu);
    Menu.setPosition({0, 0});
}

void MenuScreen::handleInput(sf::RenderWindow& window) {
    sf::Mouse mouse;
    if (mouse.isButtonPressed(mouse.Left)) {
        auto mouse_position = mouse.getPosition(window);
        int mouse_x = mouse_position.x, mouse_y = mouse_position.y;
        bool flag = false;
        if (mouse_x >= 60 && mouse_x <= 460) {
            if (mouse_y >= 240 && mouse_y <= 340)
                flag = true, Game::difficulty = 44;
            if (mouse_y >= 350 && mouse_y <= 450)
                flag = true, Game::difficulty = 37;
            if (mouse_y >= 460 && mouse_y <= 560)
                flag = true, Game::difficulty = 30;
            if (mouse_y >= 570 && mouse_y <= 670)
                flag = true, Game::difficulty = 24;
            if (flag)
                Game::Screen = std::make_shared<GameScreen>();
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
}
void MenuScreen::render(sf::RenderWindow& window) {
    window.draw(Menu);
}