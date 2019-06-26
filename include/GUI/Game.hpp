/*
** EPITECH PROJECT, 2019
** Game.hpp
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <irrlicht.h>
#include <vector>
#include <map>
#include <memory>
#include "Map.hpp"
#include "menu/EscMenu.hpp"
#include "./Character.hpp"
#include "../event/KeyboardEvent.hpp"
#include "../sound/Music.hpp"
#include "../Core.hpp"

class Game {
    public:
        Game(Core *core, KeyboardEvent &keyboardEvent, int nb_player);
        ~Game();
        void runGame();
        void loadPlayers();
        void loadMap();
        void loadCollisions();
        void loadSounds();
        void loadControls(int player);
        void loadEscController();
        void characterInteractions();
        void getCoreVariableValues(Core *core);
        void getTextures();

        void escContinue();

    private:
        int nbPlayers;
        irr::video::IVideoDriver *_driver;
        irr::IrrlichtDevice *_device;
        irr::scene::ISceneManager *_sceneManager;
        irr::gui::IGUIEnvironment *_gui;
        std::map<std::string, std::unique_ptr<Music>> _sounds;
        std::vector<std::unique_ptr<Character>> _characters;
        std::vector<std::string> _pathTextures;
        std::map<EscMenuController, std::function<void()>> _escMenuController;
        Map *_map;
        KeyboardEvent &_key;
        EscMenu *_escMenu;
        int _nb_players;
        int _width;
        int _height;
};

#endif /* !GAME_HPP_ */
