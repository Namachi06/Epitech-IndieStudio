/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** Characters
*/

#include <iostream>
#include "../../include/GUI/Character.hpp"

Character::Character(std::string const texturePath, irr::IrrlichtDevice *device,
    irr::core::vector3df const &pos, KeyboardEvent &key, Map &map) :
    _texturePath(texturePath), _device(device), _pos(pos), _key(key), _map(map)
{
    _playerControl = UNDEFINED;
    _sceneManager = _device->getSceneManager();
    _driver = _device->getVideoDriver();
    loadCharacterModel();
    setCharacterOptions();
}

Character::~Character()
{
    _triangleSelector->drop();
    _model->removeAnimators();
    _sceneManager->addToDeletionQueue(_model);
}

void Character::loadCharacterModel()
{
    _model = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/models/player.md2"));
    _model->setMaterialTexture(0, _driver->getTexture(_texturePath.c_str()));
    _model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _model->setMD2Animation(irr::scene::EMAT_STAND);
    _model->setName("Bomber");
    _model->setPosition(_pos);
    _triangleSelector = _sceneManager->createOctreeTriangleSelector(_model->getMesh(), _model, 128);
    _model->setTriangleSelector(_triangleSelector);
}

void Character::setCharacterOptions()
{
    _speed = 15.f;
    _bombPower = 2;
    _bombTimer = 3000;
    _maxBomb = 1;
    _then = _device->getTimer()->getTime();
}

CharacterEvent &Character::controls()
{
    return (_characterEvent);
}

void Character::update()
{
    _now = _device->getTimer()->getTime();
    _frame = static_cast<irr::f32>(_now - _then) / 120.f;
    _then = _now;
    if (!(moveForward() || moveBackward() || moveLeft() || moveRight()) && _playerControl != UNDEFINED) {
        _playerControl = UNDEFINED;
        _model->setMD2Animation(irr::scene::EMAT_STAND);
    }
    placeBomb();
    bombChecker();
}

void Character::setCollision(irr::scene::IAnimatedMeshSceneNode *model)
{
    irr::scene::ISceneNodeAnimator *collision;

    collision = _sceneManager->createCollisionResponseAnimator(_triangleSelector, model,
        irr::core::vector3df(10, 10, 10), irr::core::vector3df(0, 0, 0),
        irr::core::vector3df(0, 0, 0));
    model->addAnimator(collision);
    collision->drop();
}

bool Character::moveForward()
{
    irr::core::vector3df pos;

    if (!_key.IsKeyDown(_characterEvent.getForward()))
        return (false);
    pos = _model->getPosition();
    if (_playerControl != FORWARD) {
        _model->setMD2Animation(irr::scene::EMAT_RUN);
        _model->setRotation(irr::core::vector3df(0.0, 270.0, 0.0));
        _playerControl = FORWARD;
    }
    pos.Z += _speed * _frame;
    _model->setPosition(pos);
    return (true);
}

bool Character::moveBackward()
{
    irr::core::vector3df pos;

    if (!_key.IsKeyDown(_characterEvent.getBackward()))
        return (false);
    pos = _model->getPosition();
    if (_playerControl != BACKWARD) {
        _model->setMD2Animation(irr::scene::EMAT_RUN);
        _model->setRotation(irr::core::vector3df(0.0, 90.0, 0.0));
        _playerControl = BACKWARD;
    }
    pos.Z -= _speed * _frame;
    _model->setPosition(pos);
    return (true);
}

bool Character::moveLeft()
{
    irr::core::vector3df pos;

    if (!_key.IsKeyDown(_characterEvent.getLeft()))
        return (false);
    pos = _model->getPosition();
    if (_playerControl != LEFT) {
        _model->setMD2Animation(irr::scene::EMAT_RUN);
        _model->setRotation(irr::core::vector3df(0.0, 180.0, 0.0));
        _playerControl = LEFT;
    }
    pos.X -= _speed * _frame;
    _model->setPosition(pos);
    return (true);
}

bool Character::moveRight()
{
     irr::core::vector3df pos;

    if (!_key.IsKeyDown(_characterEvent.getRight()))
        return (false);
    pos = _model->getPosition();
    if (_playerControl != RIGHT) {
        _model->setMD2Animation(irr::scene::EMAT_RUN);
        _model->setRotation(irr::core::vector3df(0.0, 0.0, 0.0));
        _playerControl = RIGHT;
    }
    pos.X += _speed * _frame;
    _model->setPosition(pos);
    return (true);
}

bool Character::placeBomb()
{
    if (_key.IsKeyDown(_characterEvent.getPlaceBomb()) && _maxBomb > _bombs.size())
        _bombs.emplace(std::unique_ptr<Clock::Time>(new Clock::Time()), std::unique_ptr<Bomb>(new Bomb(_device, _model)));
    else
        return (false);
    return (true);
}

void Character::bombChecker()
{
    std::map<std::unique_ptr<Clock::Time>, std::unique_ptr<Bomb>>::iterator it;

    if (_bombs.empty())
        return;
    for (it = _bombs.begin(); it != _bombs.end(); it++) {
        if (it->first->getElapsedTime().getAsMiliseconds() >= _bombTimer) {
            // it->second->exploseBomb(_bombPower, _map);
            _bombs.erase(it->first);
            return;
        }
    }
}

irr::scene::IAnimatedMeshSceneNode *Character::getModel() const
{
    return (_model);
}

irr::f32 Character::getSpeed(void) 
{
	return this->_speed;
}

void Character::setSpeed(irr::f32 speed)
{
	this->_speed = speed;
}

irr::core::vector3df const Character::getPos(void)
{
	return this->_pos;
}

unsigned int Character::getMaxBomb(void)
{
	return this->_maxBomb;
}

void Character::setMaxBomb(unsigned int maxBomb)
{
	this->_maxBomb = maxBomb;
}

unsigned int Character::getBombPower(void)
{
	return this->_bombPower;
}

void Character::setBombPower(unsigned int bombPower)
{
	this->_bombPower = bombPower;
}
