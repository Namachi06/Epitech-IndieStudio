/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** Character header
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <map>
#include <functional>
#include "../event/KeyboardEvent.hpp"
#include "../event/CharacterEvent.hpp"
#include "../common/Time.hpp"
#include "./Map.hpp"
#include "./Bomb.hpp"

enum PlayerControls
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    PLACE_BOMB,
    UNDEFINED
};

class Character {
    public:
        Character(std::string const texturePath, irr::IrrlichtDevice *device,
            irr::core::vector3df const &pos, KeyboardEvent &key, Map &map);
        ~Character();
        void loadCharacterModel();
        void setCharacterOptions();
        CharacterEvent &controls();
        void update();
        void setCollision(irr::scene::IAnimatedMeshSceneNode *model);

        bool moveForward();
        bool moveBackward();
        bool moveLeft();
        bool moveRight();
        bool placeBomb();
        void bombChecker();

        irr::scene::IAnimatedMeshSceneNode *getModel() const;
        irr::f32 getSpeed(void);
        void setSpeed(irr::f32 speed);
        irr::core::vector3df const getPos(void);
        unsigned int getMaxBomb(void);
        void setMaxBomb(unsigned int maxBomb);
        unsigned int getBombPower(void);
        void setBombPower(unsigned int bombPower);

    private:
        CharacterEvent _characterEvent;
        std::string _texturePath;
        irr::IrrlichtDevice *_device;
        irr::core::vector3df const &_pos;
        KeyboardEvent &_key;
        Map &_map;
        irr::scene::ISceneManager *_sceneManager;
        irr::scene::IAnimatedMeshSceneNode *_model;
        irr::video::IVideoDriver *_driver;
        irr::scene::ITriangleSelector *_triangleSelector;
        irr::f32 _speed;
        irr::f32 _frame;
        irr::u32 _now;
        irr::u32 _then;
        std::map<std::unique_ptr<Clock::Time>, std::unique_ptr<Bomb>> _bombs;
        unsigned int _maxBomb;
        unsigned int _bombPower;
        long int _bombTimer;
        PlayerControls _playerControl;
};

#endif /* !CHARACTER_HPP_ */
