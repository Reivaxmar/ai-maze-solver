#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

class Character {
public:
    int gridX;
    int gridY;
    sf::Color color;
    float cellSize;
    
    Character(int x, int y, sf::Color color, float cellSize);
    void draw(sf::RenderWindow& window);
    bool tryMove(int dx, int dy, Grid& grid);
};

#endif
