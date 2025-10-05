#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell {
public:
    bool topWall;
    bool bottomWall;
    bool leftWall;
    bool rightWall;
    int x;
    int y;
    float cellSize;

    Cell(int x, int y, float cellSize);
    void draw(sf::RenderWindow& window);
};

#endif
