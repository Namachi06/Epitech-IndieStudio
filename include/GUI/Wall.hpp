/*
** EPITECH PROJECT, 2019
** Wall.hpp
** File description:
** Breakable Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_

#include <irrlicht.h>

class Wall {
	public:
		Wall(irr::core::vector3df const &pos, irr::IrrlichtDevice *device);
		~Wall();
		void loadWallScene(irr::video::IVideoDriver *driver);
		void assignWallCollision(irr::scene::IAnimatedMeshSceneNode *model);
		irr::core::vector3df const &getWallPosition() const;

	private:
		irr::core::vector3df _wallPos;
		irr::scene::ITriangleSelector *_triangleSelector;
		irr::scene::ISceneManager *_scene;
		irr::scene::IMeshSceneNode *_wall;
};

#endif /* !WALL_HPP_ */
