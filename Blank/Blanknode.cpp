#include "Blank/Blanknode.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

using namespace Sudoku;

sf::Texture num_texture[10], shape_texture[5];
bool unloaded=0;
BlankNode::BlankNode(sf::Vector2f position) : position_(position) {
    if (!unloaded) {
        for (int i = 1; i < 10; i++) {
            num_texture[i].loadFromFile("Resource/" + std::to_string(i) +
                                        ".png");
        }
        num_texture[0].loadFromFile("Resource/10.png");
        shape_texture[0].loadFromFile("Resource/10.png");
        shape_texture[1].loadFromFile("Resource/00.png");
        shape_texture[2].loadFromFile("Resource/01.png");
        shape_texture[3].loadFromFile("Resource/11.png");
        shape_texture[4].loadFromFile("Resource/target.png");
        unloaded=1;
    }
    shape_.setTexture(shape_texture[0]);
    num_.setTexture(num_texture[0]);
    shape_.setPosition(position_);
    num_.setPosition(position_);
}

void BlankNode::render(sf::RenderWindow& window, int num, int shape) {
    shape_.setPosition(position_);
    num_.setPosition(position_);
    shape_.setTexture(shape_texture[shape]);
    window.draw(shape_);
    num_.setTexture(num_texture[num]);
    window.draw(num_);
}