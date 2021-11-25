#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
    virtual void interact(Entity *) = 0;
};

#endif // ENTITY_H