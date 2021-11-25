#include "field_builder.h"
#include <iostream>

FieldBuilder::FieldBuilder()
    : target(new Field()),
      tilemap(nullptr),
      buildDone(false) {}



FieldBuilder::~FieldBuilder()
{
    if (tilemap) {
        delete [] tilemap;
    }
}

void FieldBuilder::loadFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("Field Builder: failed to load tilemap from file");

    size_t w, h;
    file >> w >> h;
    target->setWidth(w);
    target->setHeight(h);

    this->tilemap = new unsigned short [w * h];
    for (size_t i = 0; i < w * h; i++) {
        file >> tilemap[i];
    }

    file.close();
}

void FieldBuilder::build()
{
    if (!tilemap)
        throw std::runtime_error("Field Builder: no tilemap given");

    size_t width = target->getWidth();
    size_t height = target->getHeight();
    target->tiles = new Tile* [width];
    for (size_t x = 0; x < width; x++) {
       target->tiles[x] = new Tile [height];
        for (size_t y = 0; y < height; y++) {
            target->tiles[x][y] = Tile((TileType)tilemap[y + x*height]);
        }
    }

    delete [] tilemap;
    tilemap = nullptr;
    buildDone = true;
}

void FieldBuilder::placeHero()
{
    //TODO (LB2)
}

void FieldBuilder::placeEnemies()
{
    //TODO (LB2)
}

void FieldBuilder::placeItems()
{
    //TODO (LB2)
}

Field *FieldBuilder::getResult()
{
    if (!buildDone)
        throw std::runtime_error("Field Builder: building gone wrong");
    Field *result = target;
    reset();
    return result;
}

void FieldBuilder::reset()
{
    if (tilemap) 
        delete [] tilemap;
    target = nullptr;
}