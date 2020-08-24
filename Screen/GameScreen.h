#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Blank/Blank.h"
#include "Game/Game.h"
#include "Screen/Screen.h"

namespace Sudoku {
class GameScreen : public Screen {
   public:
    GameScreen();

    void handleInput(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

   private:
    Blank blank;
    sf::Sprite gameScreen;
};
}  // namespace Sudoku

#endif