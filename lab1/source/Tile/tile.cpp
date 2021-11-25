#include "tile.h"

Tile::Tile(TileType type)
    : type(type),
      entity(nullptr) {}

Tile& Tile::operator=(const Tile& other)
{
    type = other.getType();
    return *this;
}

TileType Tile::getType() const
{
    return type;
}

const Entity &Tile::getEntity() const
{
    return *entity;
}