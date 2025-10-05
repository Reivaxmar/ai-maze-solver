#include "Character.h"

Character::Character(int x, int y, sf::Color color, float cellSize) 
    : gridX(x), gridY(y), color(color), cellSize(cellSize) {
}

void Character::draw(sf::RenderWindow& window) {
    float pixelX = gridX * cellSize + cellSize / 2;
    float pixelY = gridY * cellSize + cellSize / 2;
    float radius = cellSize / 3;
    
    sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setOrigin(radius, radius);
    circle.setPosition(pixelX, pixelY);
    window.draw(circle);
}

bool Character::tryMove(int dx, int dy, Grid& grid) {
    int newX = gridX + dx;
    int newY = gridY + dy;
    
    // Check bounds
    if (newX < 0 || newX >= grid.gridWidth || newY < 0 || newY >= grid.gridHeight) {
        return false;
    }
    
    // Check wall collision
    Cell& currentCell = grid.getCell(gridX, gridY);
    
    // Check if moving right
    if (dx > 0 && currentCell.rightWall) {
        return false;
    }
    // Check if moving left
    if (dx < 0 && currentCell.leftWall) {
        return false;
    }
    // Check if moving down
    if (dy > 0 && currentCell.bottomWall) {
        return false;
    }
    // Check if moving up
    if (dy < 0 && currentCell.topWall) {
        return false;
    }
    
    // Move is valid
    gridX = newX;
    gridY = newY;
    return true;
}
