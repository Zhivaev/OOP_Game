#ifndef APP_H
#define APP_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../Field/field.h"
#include "../FieldBuilder/field_builder.h"
#include "../View/view.h"

class App
{
public:
    App();
    ~App();

    void start();
    
private:
    void initWindow();
    void initField();
    void initView();

    void updateEvents();
    void updateLogic();
    void render();

    sf::RenderWindow* window;
    sf::Event event;

    Field* field;
    View* view;
};

#endif // APP_H