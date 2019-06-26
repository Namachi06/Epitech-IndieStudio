/*
** EPITECH PROJECT, 2019
** PowerUp.hpp
** File description:
** PowerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_


#include "../../include/GUI/Character.hpp"
#include "../../include/exception/IndieStudioExceptions.hpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

enum PowerUpType
{
    BOMBUP,
    SPEEDUP,
    FIREUP,
    WALLPASS
};

class PowerUp : public irr::scene::ICollisionCallback
{
	public:
		PowerUp(irr::core::vector3df const &_pos, std::vector<std::unique_ptr<Character>> character);
		~PowerUp();


		bool onCollision();
		bool PowerUpEffect(std::vector<std::unique_ptr<Character>> *usrs, int mem);
		bool createPowerUp(void);
		void setType(PowerUpType _type);
		PowerUpType getType(void);
		irr::core::vector3df const getPos(void);
		std::vector<std::unique_ptr<Character>> *getCharactere(void);
		void setUsed(bool _used);
		bool getUsed(void);

	private:
		irr::core::vector3df const &pos;
		PowerUpType type;
		bool used;
		std::vector<std::unique_ptr<Character>> *character;
		irr::scene::IAnimatedMeshSceneNode *modelPowerUp;
		irr::scene::ITriangleSelector *triangleSelector;
		irr::scene::ISceneManager *sceneManager;
};

#endif /* !POWERUP_HPP_ */