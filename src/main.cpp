#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Character.h"

int main() {
    // Window settings
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;
    const int GRID_SIZE = 10;
    const float CELL_SIZE = WINDOW_WIDTH / GRID_SIZE;
    
    // Create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "AI Maze Solver");
    window.setFramerateLimit(60);
    
    // Create grid
    Grid grid(GRID_SIZE, GRID_SIZE, CELL_SIZE);
    
    // Create characters - user (blue) and AI (red)
    Character user(0, 0, sf::Color::Blue, CELL_SIZE);
    Character ai(GRID_SIZE - 1, GRID_SIZE - 1, sf::Color::Red, CELL_SIZE);
    
    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Handle key press events
            if (event.type == sf::Event::KeyPressed) {
                // Handle WASD keys
                if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
                    user.tryMove(0, -1, grid);
                }
                if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
                    user.tryMove(0, 1, grid);
                }
                if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                    user.tryMove(-1, 0, grid);
                }
                if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                    user.tryMove(1, 0, grid);
                }
            }
        }
        
        // Clear window
        window.clear(sf::Color::Black);
        
        // Draw grid
        grid.draw(window);
        
        // Draw characters
        user.draw(window);
        ai.draw(window);
        
        // Display
        window.display();
    }
    
    return 0;
}