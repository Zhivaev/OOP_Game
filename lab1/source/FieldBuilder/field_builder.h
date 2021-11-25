#ifndef FIELD_BUILDER_H
#define FIELD_BUILDER_H

#include "fstream"

#include "../Field/field.h"

class FieldBuilder
{
public:
    FieldBuilder();
    ~FieldBuilder();

    void loadFromFile(std::string fileName);
    void build();
    void placeHero();
    void placeEnemies();
    void placeItems();

    Field *getResult();

private:
    void reset();

    unsigned short *tilemap;
    Field *target;

    bool buildDone;
};

#endif // FIELD_BUILDER_H#endif // FIELD_BUILDER_H