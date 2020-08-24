#ifndef BLANK_H
#define BLANK_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#include "Blank/Blanknode.h"

namespace Sudoku {
class Blank {
   public:
    Blank(int difficulty);

    void handleInput(sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);

   private:
    bool mut_map[10][10];
    int now_map[10][10];
    int target_x;
    int target_y;
    void reset();
    sf::Clock clock;
    sf::Font font_;
    sf::Text text_;

    BlankNode nodes[10][10]; 
};
}  // namespace Sutoku

#endif