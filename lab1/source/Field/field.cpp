#include "field.h"

Field::Field()
    : tiles(nullptr) {}

Field::~Field()
{
    for (size_t x = 0; x < width; x++) {
        delete[] this->tiles[x];
    }
    delete[] this->tiles;
}

Field::Field(const Field &other)
    : width(other.width),
      height(other.height)
{
    this->tiles = new Tile *[width];
    for (size_t x = 0; x < width; x++)
    {
        this->tiles[x] = new Tile[height];
        for (size_t y = 0; y < height; y++)
        {
            tiles[x][y] = other.tiles[x][y];
        }
    }
}

Field::Field(Field &&other)
    : tiles(other.tiles),
      width(other.width),
      height(other.height)
{
    other.tiles = nullptr;
}

Field &Field::operator=(const Field &other)
{
    if (this == &other)
        return *this;

    for (size_t x = 0; x < this->width; x++)
    {
        delete[] this->tiles[x];
    }
    delete[] this->tiles;

    this->width = other.width;
    this->height = other.height;

    this->tiles = new Tile *[this->width];
    for (size_t x = 0; x < this->width; x++)
    {
        this->tiles[x] = new Tile[this->height];
        for (size_t y = 0; y < this->height; y++)
        {
            this->tiles[x][y] = other.tiles[x][y];
        }
    }
    return *this;
}

Field &Field::operator=(Field &&other)
{
    if (&other == this)
        return *this;

    for (int x = 0; x < width; x++)
        delete[] tiles[x];
    delete[] tiles;

    width = other.width;
    height = other.height;
    tiles = other.tiles;

    other.tiles = nullptr;

    return *this;
}

void Field::setWidth(size_t width)
{
    this->width = width;
}

void Field::setHeight(size_t height)
{
    this->height = height;
}

size_t Field::getWidth() const
{
    return width;
}

size_t Field::getHeight() const
{
    return height;
}