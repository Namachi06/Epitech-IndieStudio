/*
** EPITECH PROJECT, 2019
** Map.hpp
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <irrlicht.h>
#include <vector>
#include <memory>
#include "./Wall.hpp"

class Map {
    public:
        Map(irr::IrrlichtDevice *device);
        ~Map();
        void loadMap(irr::core::array<irr::scene::ISceneNode *> nodes);
        void loadSpawns();
        void randomWallGenerator();
        void getMapGrid();
        irr::core::vector3df getSpawnAtPosition(int position) const;
        std::vector<irr::core::vector3df> getSpawns() const;
        void setCollision(irr::scene::IAnimatedMeshSceneNode *model);
        bool removeWallAtPosition(irr::core::vector3df const &pos1, irr::core::vector3df const &pos);

    private:
        irr::scene::IMetaTriangleSelector *_metaTriangle;
        irr::IrrlichtDevice *_device;
        irr::scene::ISceneManager *_scene;
        std::vector<std::unique_ptr<Wall>> _walls;
        std::vector<std::string> _mapGrid;
        std::vector<irr::core::vector3df> _spawnPositions;
};

#endif /* !MAP_HPP_ */
