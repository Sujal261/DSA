#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rod with Rings");

    // Rod setup (vertical)
    sf::RectangleShape rod(sf::Vector2f(20, 400)); // width x height
    rod.setFillColor(sf::Color(100, 100, 100));   // grey rod
    rod.setOrigin(10, 200); // center origin
    rod.setPosition(400, 300); // center of window

    // Ring setup
    std::vector<sf::CircleShape> rings;
    const int numRings = 7;
    float rodTop = 300 - 200;
    float spacing = 400.0f / (numRings + 1);

    for (int i = 0; i < numRings; ++i) {
        sf::CircleShape ring(20); // radius of ring
        ring.setOrigin(20, 20);
        ring.setFillColor(sf::Color::Transparent); // hollow center
        ring.setOutlineThickness(4);               // ring thickness
        ring.setOutlineColor(sf::Color::Red);      // ring color
        ring.setPosition(400, rodTop + spacing * (i + 1));
        rings.push_back(ring);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear(sf::Color::Black);
        window.draw(rod);
        for (auto& ring : rings)
            window.draw(ring);
        window.display();
    }

    return 0;
}
