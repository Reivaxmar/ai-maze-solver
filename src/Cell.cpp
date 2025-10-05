#include "Cell.h"

Cell::Cell(int x, int y, float cellSize) 
    : x(x), y(y), cellSize(cellSize), 
      topWall(true), bottomWall(true), leftWall(true), rightWall(true) {
}

void Cell::draw(sf::RenderWindow& window) {
    float pixelX = x * cellSize;
    float pixelY = y * cellSize;
    
    sf::Color wallColor = sf::Color::White;
    float wallThickness = 2.0f;
    
    // Draw top wall
    if (topWall) {
        sf::RectangleShape wall(sf::Vector2f(cellSize, wallThickness));
        wall.setPosition(pixelX, pixelY);
        wall.setFillColor(wallColor);
        window.draw(wall);
    }
    
    // Draw bottom wall
    if (bottomWall) {
        sf::RectangleShape wall(sf::Vector2f(cellSize, wallThickness));
        wall.setPosition(pixelX, pixelY + cellSize - wallThickness);
        wall.setFillColor(wallColor);
        window.draw(wall);
    }
    
    // Draw left wall
    if (leftWall) {
        sf::RectangleShape wall(sf::Vector2f(wallThickness, cellSize));
        wall.setPosition(pixelX, pixelY);
        wall.setFillColor(wallColor);
        window.draw(wall);
    }
    
    // Draw right wall
    if (rightWall) {
        sf::RectangleShape wall(sf::Vector2f(wallThickness, cellSize));
        wall.setPosition(pixelX + cellSize - wallThickness, pixelY);
        wall.setFillColor(wallColor);
        window.draw(wall);
    }
}
