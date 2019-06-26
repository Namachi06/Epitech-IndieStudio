/*
** EPITECH PROJECT, 2019
** Bomb.cpp
** File description:
** Bomb
*/

#include <iostream>
#include "../../include/GUI/Bomb.hpp"
#include "../../include/exception/IndieStudioExceptions.hpp"

Bomb::Bomb(irr::IrrlichtDevice *_device, irr::scene::IAnimatedMeshSceneNode *modelChar) :
    _device(_device), _modelChar(modelChar)
{
    _driver = _device->getVideoDriver();
    _sceneManager = _device->getSceneManager();
    loadBomb();
    std::cout << "Bomb loaded" << std::endl;
}

Bomb::~Bomb()
{
    _sceneManager->addToDeletionQueue(_modelBomb);
    _sceneManager->addToDeletionQueue(_particle);
    _triangleSelector->drop();
}

void Bomb::loadBomb()
{
    irr::scene::IParticleEmitter *emitter;

    _modelBomb = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/models/bombe.3DS"));
    if (!_modelBomb)
        throw ISException::IrrlichtException("Bomb model not found");
    _bombPos = _modelChar->getPosition();
    _modelBomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _modelBomb->setPosition(irr::core::vector3df(_bombPos.X, 30.f, _bombPos.Z));
    _modelBomb->setRotation(irr::core::vector3df(0.f, 100.f, 0.f));
    _triangleSelector = _sceneManager->createOctreeTriangleSelector(_modelBomb->getMesh(), _modelBomb, 128);
    _modelBomb->setTriangleSelector(_triangleSelector);
    _particle = _sceneManager->addParticleSystemSceneNode(false);
    emitter = _particle->createBoxEmitter(irr::core::aabbox3d<irr::f32>
        (_bombPos.X + 2.0f, 39.0f, _bombPos.Z, _bombPos.X + 2.0f, 39.0f, _bombPos.Z));
    _particle->setEmitter(emitter);
    emitter->drop();
    _particle->setMaterialTexture(0, _driver->getTexture("./assets/textures/fire.bmp"));
    _particle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _particle->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    _particle->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

void Bomb::exploseBomb(unsigned int bombPower, Map &map)
{
    explosionDirection(irr::core::vector3df(0.0f, 0.0f, 50.0f), map, bombPower);
    explosionDirection(irr::core::vector3df(0.0f, 0.0f, -50.0f), map, bombPower);
    explosionDirection(irr::core::vector3df(50.0f, 0.0f, 0.0f), map, bombPower);
    explosionDirection(irr::core::vector3df(-50.0f, 0.0f, 0.0f), map, bombPower);
}

void Bomb::explosionDirection(irr::core::vector3df const direction, Map &map, unsigned int bombPower)
{
    for (unsigned int i = 1; i <= bombPower; i++) {
        if (!map.removeWallAtPosition(irr::core::vector3df(_bombPos.X, 30.f, _bombPos.Z),
            irr::core::vector3df(_bombPos.X, 30.f, _bombPos.Z) + (direction * i)))
            return;
    }
}
