#include "Grid.h"

Grid::Grid(int width, int height, float cellSize) 
    : gridWidth(width), gridHeight(height), cellSize(cellSize) {
    // Initialize the grid with cells
    for (int y = 0; y < gridHeight; y++) {
        std::vector<Cell> row;
        for (int x = 0; x < gridWidth; x++) {
            row.push_back(Cell(x, y, cellSize));
        }
        cells.push_back(row);
    }
}

void Grid::draw(sf::RenderWindow& window) {
    for (int y = 0; y < gridHeight; y++) {
        for (int x = 0; x < gridWidth; x++) {
            cells[y][x].draw(window);
        }
    }
}

Cell& Grid::getCell(int x, int y) {
    return cells[y][x];
}
