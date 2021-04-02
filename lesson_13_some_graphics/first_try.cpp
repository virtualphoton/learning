#include <SFML/Graphics.hpp>
#include <vector>

using std::vector;
int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Never given", sf::Style::Close);
    window.setFramerateLimit(100);

    sf::RectangleShape  under(sf::Vector2f(1024, 768));
    sf::RectangleShape mid(sf::Vector2f(150, 1000));
    under.setFillColor(sf::Color(244, 228, 128));
    mid.setFillColor(sf::Color (0, 171, 255));
    mid.setPosition(310, 0);
    mid.setRotation(-20);
    vector<sf::RectangleShape> rec_shapes;
    rec_shapes.push_back(under);
    rec_shapes.push_back(mid);

    sf::ConvexShape main;
    main.setPointCount(7);
    main.setPoint(0, sf::Vector2f(0, 0));
    main.setPoint(1, sf::Vector2f(150, 0));

    main.setPoint(2, sf::Vector2f(163, 12.5));
    main.setPoint(3, sf::Vector2f(170, 25));
    main.setPoint(4, sf::Vector2f(163, 37.5));

    main.setPoint(5, sf::Vector2f(150, 50));
    main.setPoint(6, sf::Vector2f(0, 50));
    main.setFillColor(sf::Color (224, 224, 224));
    main.setOutlineColor(sf::Color::Black);
    main.setOutlineThickness(10);
    main.setPosition(500, 470);
    main.setRotation(-80);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        for (auto shape : rec_shapes)
            window.draw(shape);
        window.draw(main);
        window.display();
    }
    return 0;
}