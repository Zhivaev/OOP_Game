cmake_minimum_required(VERSION 3.0.0)
project(Game VERSION 0.1.0)

set (
    APP
    source/App/app.cpp
    source/App/app.h
)

set (
    FIELD
    source/Field/field.cpp
    source/Field/field.h
)

set (
    FIELD_BUIDLER
    source/FieldBuilder/field_builder.cpp
    source/FieldBuilder/field_builder.h
)

set (
    VIEW
    source/View/view.cpp
    source/View/view.h
)

set (
    TILE
    source/Tile/tile.cpp 
    source/Tile/tile.h
)

set (
    ENTITY
    source/Entity/entity.h
)

add_executable(
    Game 
    source/main.cpp
    ${APP}
    ${FIELD}
    ${FIELD_BUIDLER}
    ${VIEW}
    ${TILE}
    ${ENTITY}
)

set (
    GLIBS
    sfml-graphics
    sfml-system
    sfml-window
)

target_link_libraries(Game ${GLIBS})