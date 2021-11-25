#ifndef FIELD_H
#define FIELD_H

#include <cstddef>

#include "../Tile/tile.h"

class Field
{
public:
    Field();
    ~Field();

    Field(const Field&);
    Field(Field&&);

    Field& operator=(const Field&);
    Field& operator=(Field&&);

    void setWidth(size_t);
    void setHeight(size_t);

    size_t getWidth() const;
    size_t getHeight() const;

    Tile **tiles;

private: 
    size_t width;
    size_t height;
};

#endif // FIELD_H
