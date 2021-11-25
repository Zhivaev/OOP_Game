#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

#include "../Field/field.h"

class View : public sf::Drawable, public sf::Transformable
{
public:
    View(Field *);

    void loadFromFile(const char*, sf::Vector2u);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

    Field *target;
};

#endif // VIEW_H