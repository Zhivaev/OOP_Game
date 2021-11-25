#include "app.h"

App::App()
{
    initField();
    initWindow();
    initView();
}

App::~App()
{
    delete window;
    delete field;
    delete view;
}

void App::start()
{
    while (window->isOpen())
    {
        updateEvents();
        updateLogic();
        render();
    }
}

void App::initWindow()
{
    if (!field)
        throw std::runtime_error("Field was not initialized before window"); 
    window = new sf::RenderWindow(sf::VideoMode(field->getWidth()*32, field->getHeight()*32), "The Game");
}

void App::initField()
{
    FieldBuilder fieldBuilder;
    fieldBuilder.loadFromFile("../settings/tilemap.txt");
    fieldBuilder.placeHero();
    fieldBuilder.placeEnemies();
    fieldBuilder.placeItems();
    fieldBuilder.build();
    field = fieldBuilder.getResult();
}

void App::initView()
{
    if (!field)
        throw std::runtime_error("Field was not initialized before view"); 
    view = new View(field);
    view->loadFromFile("../images/tileset.png", sf::Vector2u(32u, 32u));
}

void App::updateEvents()
{
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void App::updateLogic()
{
    
}

void App::render()
{
    window->clear();

    window->draw(*view);

    window->display();
}
