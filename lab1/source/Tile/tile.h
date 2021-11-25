#ifndef TILE_H
#define TILE_H

#include "../Entity/entity.h"

enum TileType {WALL, GROUND, ENTRANCE, EXIT};

class Tile
{
public:
    Tile(TileType type = WALL);

    Tile& operator=(const Tile&); 

    TileType getType() const;

    const Entity &getEntity() const;

private:
    Entity *entity;
    TileType type;
};

#endif // TILE_H