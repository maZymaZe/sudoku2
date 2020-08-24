#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace Sudoku {
class GameOverScreen : public Screen {
   public:
    GameOverScreen();
    void handleInput(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
   private:
    sf::Sprite game_over_screen;
};
}  // namespace Sudoku

#endif