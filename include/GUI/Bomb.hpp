/*
** EPITECH PROJECT, 2019
** Bomb.hpp
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "../sound/Music.hpp"
#include "./Map.hpp"
#include <irrlicht.h>

class Bomb {
	public:
		Bomb(irr::IrrlichtDevice *_device, irr::scene::IAnimatedMeshSceneNode *modelChar);
		~Bomb();
        void loadBomb();
        void exploseBomb(unsigned int bombPower, Map &map);
        void explosionDirection(irr::core::vector3df const direction, Map &map, unsigned int bombPower);

	private:
        irr::IrrlichtDevice *_device;
        irr::video::IVideoDriver *_driver;
        irr::scene::IAnimatedMeshSceneNode *_modelChar;
        irr::scene::IAnimatedMeshSceneNode *_modelBomb;
        irr::scene::ISceneManager *_sceneManager;
        irr::scene::ITriangleSelector *_triangleSelector;
        irr::scene::IParticleSystemSceneNode *_particle;
        irr::core::vector3df _bombPos;
        Music *placeBomb;
};

#endif /* !BOMB_HPP_ */
