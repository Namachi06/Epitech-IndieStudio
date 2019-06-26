/*
** EPITECH PROJECT, 2019
** Map.cpp
** File description:
** Map
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include "../../include/GUI/Map.hpp"
#include "../../include/exception/IndieStudioExceptions.hpp"

Map::Map(irr::IrrlichtDevice *device) : _device(device)
{
    irr::core::array<irr::scene::ISceneNode *> nodes;

    _scene = _device->getSceneManager();
    loadMap(nodes);
    loadSpawns();
    std::cout << "Map Ready" << std::endl;
}

Map::~Map()
{
    _metaTriangle->drop();
}

void Map::loadMap(irr::core::array<irr::scene::ISceneNode *> nodes)
{
    irr::scene::ITriangleSelector *triangleSelector;

    getMapGrid();
    if (!_scene->loadScene("./assets/map/map.irr"))
        throw ISException::IrrlichtException("Can't load the map");
    _scene->getSceneNodesFromType(irr::scene::ESNT_CUBE, nodes);
    _scene->addCameraSceneNode(NULL, irr::core::vector3df(0, 430, -120),
        irr::core::vector3df(0, 0, 0));
    _metaTriangle = _scene->createMetaTriangleSelector();
    for (unsigned int i = 0; i < nodes.size(); i++) {
        triangleSelector = _scene->createTriangleSelectorFromBoundingBox(nodes[i]);
        if (triangleSelector) {
            _metaTriangle->addTriangleSelector(triangleSelector);
            triangleSelector->drop();
        }
    }
    randomWallGenerator();
}

void Map::loadSpawns()
{
    _spawnPositions.push_back(irr::core::vector3df(-300.f, 30.f, 300.f));
    _spawnPositions.push_back(irr::core::vector3df(300.f, 30.f, -200.f));
    _spawnPositions.push_back(irr::core::vector3df(-300.f, 30.f, -200.f));
    _spawnPositions.push_back(irr::core::vector3df(300.f, 30.f, 300.f));
}

void Map::randomWallGenerator()
{
    std::vector<std::string>::iterator y = _mapGrid.begin();
    irr::core::vector3df pos;

    srand(time(NULL));
    for (int posY = 0; y != _mapGrid.end(); y++, posY++) {
        for (int x = 0; (*y)[x]; x++) {
            if (rand() % 2 == 1 && (*y)[x] != 'X') {
                pos = irr::core::vector3df(50.0f * (x - 6), 30.f, 50.f * (posY - 5) + 50.f);
                _walls.push_back(std::unique_ptr<Wall>(new Wall(pos, _device)));
            }
        }
    }
}

void Map::getMapGrid()
{
    std::ifstream file("./assets/map/mapGrid.txt");
    std::string lineStr;

    if (!file.is_open())
        throw ISException::RuntimeException("Can't read the map grid");
    while (getline(file, lineStr))
        _mapGrid.push_back(lineStr);
    file.close();
}

irr::core::vector3df Map::getSpawnAtPosition(int position) const
{
    return (_spawnPositions[position]);
}

std::vector<irr::core::vector3df> Map::getSpawns() const
{
    return (_spawnPositions);
}

void Map::setCollision(irr::scene::IAnimatedMeshSceneNode *model)
{
    irr::scene::ISceneNodeAnimator *collision;
    std::vector<std::unique_ptr<Wall>>::iterator wall = _walls.begin();

    collision = _scene->createCollisionResponseAnimator(_metaTriangle, model,
        irr::core::vector3df(10, 10, 10), irr::core::vector3df(0, 0, 0),
        irr::core::vector3df(0, 0, 0));
    model->addAnimator(collision);
    collision->drop();
    for (; wall != _walls.end(); wall++)
        (*wall)->assignWallCollision(model);
}

bool Map::removeWallAtPosition(irr::core::vector3df const &pos1, irr::core::vector3df const &pos2)
{
    std::vector<std::unique_ptr<Wall>>::iterator it;

    for (it = _walls.begin(); it != _walls.end(); it++) {
        if ((*it)->getWallPosition().isBetweenPoints(pos1, pos2)) {
            _walls.erase(it);
            std::cout << "Wall gone" << std::endl;
            return (true);
        }
    }
    return (false);
}
