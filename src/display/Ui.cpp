/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** Ui
*/

#include "Ui.hpp"
#include <cmath>
#include <vector>

Ui::Ui()
{
    _topBackground = createRoundedRectangle(sf::Vector2f(0, 0), sf::Vector2f(1920, 200), 20,
        sf::Color(10, 10, 70, 255), 8);
    _background = createRoundedRectangle(sf::Vector2f(150, 230), sf::Vector2f(1540, 1080 - 300), 20,
        sf::Color(10, 10, 70, 255), 8);
}

Ui::~Ui()
{
}

sf::RectangleShape Ui::initSquare(sf::Vector2f pos, sf::Color color, sf::Vector2f size)
{
    sf::RectangleShape square(size);
    square.setPosition(pos);
    square.setFillColor(color);
    return square;
}


void Ui::display(sf::RenderWindow *window)
{
    window->draw(_topBackground);
}

sf::VertexArray Ui::getTopBackground() const
{
    return _topBackground;
}

sf::VertexArray Ui::getBackground() const
{
    return _background;
}


void addCornerVertices(sf::VertexArray& vertices, const sf::Vector2f& cornerCenter,
    float radius, float startAngle, unsigned int cornerPoints, const sf::Color& color)
{
    const float PI = 3.14159265359f;
    float angleStep = PI / 2.0f / static_cast<float>(cornerPoints);
    
    for (unsigned int i = 0; i < cornerPoints; ++i) {
        float angle1 = startAngle + i * angleStep;
        float angle2 = startAngle + (i + 1) * angleStep;
        sf::Vector2f point1(cornerCenter.x + radius * cos(angle1), cornerCenter.y + radius * sin(angle1));
        sf::Vector2f point2(cornerCenter.x + radius * cos(angle2), cornerCenter.y + radius * sin(angle2));
        
        vertices.append(sf::Vertex(cornerCenter, color));
        vertices.append(sf::Vertex(point1, color));
        vertices.append(sf::Vertex(point2, color));
    }
}

sf::VertexArray Ui::createRoundedRectangle(sf::Vector2f position, sf::Vector2f size, float radius,
    const sf::Color& color, unsigned int cornerPoints)
{
    sf::VertexArray vertices(sf::Triangles);
    radius = std::min(radius, std::min(size.x / 2.0f, size.y / 2.0f));
    sf::Vector2f topLeft(position.x + radius, position.y + radius);
    sf::Vector2f topRight(position.x + size.x - radius, position.y + radius);
    sf::Vector2f bottomRight(position.x + size.x - radius, position.y + size.y - radius);
    sf::Vector2f bottomLeft(position.x + radius, position.y + size.y - radius);
    const float PI = 3.14159265359f;

    vertices.append(sf::Vertex(sf::Vector2f(topLeft.x, position.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(topRight.x, position.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(bottomLeft.x, position.y + size.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(bottomLeft.x, position.y + size.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(topRight.x, position.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(bottomRight.x, position.y + size.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(position.x, topLeft.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(topLeft.x, topLeft.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(position.x, bottomLeft.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(position.x, bottomLeft.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(topLeft.x, topLeft.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(bottomLeft.x, bottomLeft.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(topRight.x, topRight.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(position.x + size.x, topRight.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(bottomRight.x, bottomRight.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(bottomRight.x, bottomRight.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(position.x + size.x, topRight.y), color));
    vertices.append(sf::Vertex(sf::Vector2f(position.x + size.x, bottomRight.y), color));

    addCornerVertices(vertices, topLeft, radius, PI, cornerPoints, color);
    addCornerVertices(vertices, topRight, radius, -PI / 2.0f, cornerPoints, color);
    addCornerVertices(vertices, bottomRight, radius, 0.0f, cornerPoints, color);
    addCornerVertices(vertices, bottomLeft, radius, PI / 2.0f, cornerPoints, color);
    
    return vertices;
}

void Ui::changeColor(sf::VertexArray &button, const sf::Color& color)
{
    for (size_t i = 0; i < button.getVertexCount(); ++i) {
        button[i].color = color;
    }
}