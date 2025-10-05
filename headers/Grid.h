#ifndef GRID_H
#define GRID_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"

class Grid {
public:
    int gridWidth;
    int gridHeight;
    float cellSize;
    std::vector<std::vector<Cell>> cells;

    Grid(int width, int height, float cellSize);
    void draw(sf::RenderWindow& window);
    Cell& getCell(int x, int y);
};

#endif
