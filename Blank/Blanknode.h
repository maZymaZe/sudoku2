#ifndef BLANK_NODE_H
#define BLANK_NODE_H

#include <SFML/Graphics.hpp>

namespace Sudoku {
class BlankNode {
   public:
    BlankNode(sf::Vector2f position = sf::Vector2f(0, 0));

    void render(sf::RenderWindow& window, int num, int node);

   private:
    sf::Sprite shape_;
    sf::Sprite num_;
    sf::Vector2f position_;
};
}  // namespace Sudoku

#endif