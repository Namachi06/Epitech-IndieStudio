/*
** EPITECH PROJECT, 2019
** PowerUp.cpp
** File description:
** PwowerUp
*/

#include "../../include/GUI/PowerUp.hpp"


PowerUp::PowerUp(irr::core::vector3df const &_pos, std::vector<std::unique_ptr<Character>> _character) : pos(_pos), character(&_character) {
	PowerUpType typeList[4];
    typeList[0] = BOMBUP;
    typeList[1] = SPEEDUP;
    typeList[2] = FIREUP;
    typeList[3] = WALLPASS;

    srand (time(NULL));
    int r = rand() % 4;
    PowerUp::setType(typeList[r]);
}

PowerUp::~PowerUp(void){
	this->sceneManager->addToDeletionQueue(this->modelPowerUp);
	this->triangleSelector->drop();
}

bool bombeUpPower(std::vector<std::unique_ptr<Character>> *usrs, int mem) {
	usrs->front()->getPos();
	if (mem == 0) {
		usrs->front()->setMaxBomb(usrs->front()->getMaxBomb() + 1);
		return true;
	} else {
		usrs->back()->setMaxBomb(usrs->back()->getMaxBomb() + 1);
		return true;
	}
}

bool speedUpPower(std::vector<std::unique_ptr<Character>> *usrs, int mem) {
	if (mem == 0) {
		usrs->front()->setSpeed((usrs->front()->getSpeed()) + 0.3);
		return true;
	} else {
		usrs->back()->setSpeed((usrs->back()->getSpeed()) + 0.3);
		return true;
	}
}

bool fireUpPower(std::vector<std::unique_ptr<Character>> *usrs, int mem) {
	if (mem == 0) {
		usrs->front()->setBombPower(usrs->front()->getBombPower() + 1);
		return true;
	} else {
		usrs->back()->setBombPower(usrs->back()->getBombPower() + 1);
		return true;
	}
}

bool wallPass(std::vector<std::unique_ptr<Character>> *usrs, int mem) {
	return false;
}

bool PowerUp::PowerUpEffect(std::vector<std::unique_ptr<Character>> *usrs, int mem) {
    bool (*ptrTab[4])(std::vector<std::unique_ptr<Character>> *, int) =
    {bombeUpPower, speedUpPower, fireUpPower, wallPass};
    (*ptrTab[type])(usrs, mem);
	return true;
}

bool PowerUp::onCollision() {
	if(std::abs(this->character->front()->getPos().X - this->pos.X + this->character->front()->getPos().Y - this->pos.Y)
		> std::abs(this->character->back()->getPos().X - this->pos.X + this->character->back()->getPos().Y - this->pos.Y))
		return PowerUpEffect(this->character, 1);
	else
		return PowerUpEffect(this->character, 0);
}

bool PowerUp::createPowerUp(void) {
	this->modelPowerUp = this->sceneManager->addAnimatedMeshSceneNode(this->sceneManager->getMesh("./assets/models/powerUp.3DS"));
	if (!this->modelPowerUp)
	    throw ISException::IrrlichtException("PowerUp model not found");
	this->modelPowerUp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->modelPowerUp->setPosition(irr::core::vector3df(this->pos.X, 30.f, this->pos.Z));
	this->modelPowerUp->setRotation(irr::core::vector3df(0.f, 100.f, 0.f));
    this->triangleSelector = this->sceneManager->createOctreeTriangleSelector(this->modelPowerUp->getMesh(), this->modelPowerUp, 128);
	this->modelPowerUp->setTriangleSelector(this->triangleSelector);

	return false;
}

void PowerUp::setType(PowerUpType _type) {
	this->type = _type;
}

PowerUpType PowerUp::getType(void) {
	return this->type;
}

irr::core::vector3df const PowerUp::getPos(void) {
	return this->pos;
}

std::vector<std::unique_ptr<Character>> *PowerUp::getCharactere(void) {
	return this->character;
}

void PowerUp::setUsed(bool _used) {
	this->used = _used;
}

bool PowerUp::getUsed(void) {
	return this->used;
}