/*
** EPITECH PROJECT, 2019
** Wall.cpp
** File description:
** Breakable wall
*/

#include <iostream>
#include "../../include/GUI/Wall.hpp"

Wall::Wall(irr::core::vector3df const &pos, irr::IrrlichtDevice *device)
{
    irr::video::IVideoDriver *driver;

    driver = device->getVideoDriver();
    _scene = device->getSceneManager();
    _wallPos = pos;
    loadWallScene(driver);
    std::cout << "Wall Ready" << std::endl;
}

Wall::~Wall()
{
    _triangleSelector->drop();
    _scene->addToDeletionQueue(_wall);
}

void Wall::loadWallScene(irr::video::IVideoDriver *driver)
{
    _wall = _scene->addCubeSceneNode(50.f, NULL, -1, _wallPos);
    _wall->setMaterialTexture(0, driver->getTexture("./assets/textures/wood.jpg"));
    _wall->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _triangleSelector = _scene->createOctreeTriangleSelector(_wall->getMesh(), _wall);
    _wall->setTriangleSelector(_triangleSelector);
}

void Wall::assignWallCollision(irr::scene::IAnimatedMeshSceneNode *model)
{
    irr::scene::ISceneNodeAnimator *collision;

    collision = _scene->createCollisionResponseAnimator(_triangleSelector, model,
        irr::core::vector3df(10, 10, 10), irr::core::vector3df(0, 0, 0),
        irr::core::vector3df(0, 0, 0));
    model->addAnimator(collision);
    collision->drop();
}

irr::core::vector3df const &Wall::getWallPosition() const
{
    return (_wallPos);
}
