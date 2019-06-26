/*
** EPITECH PROJECT, 2019
** Game.cpp
** File description:
** Game
*/

#include <iostream>
#include "../../include/GUI/Game.hpp"

Game::Game(Core *core, KeyboardEvent &keyboardEvent, int nb_player) : _key(keyboardEvent), _nb_players(nb_player)
{
    getCoreVariableValues(core);
    getTextures();
    loadSounds();
    loadMap();
    loadPlayers();
    loadCollisions();
    loadEscController();
    std::cout << "Game launched successfuly" << std::endl;
}

Game::~Game()
{
    delete _map;
}

void Game::runGame()
{
    EscMenuController controller = ESC_NONE;

    _device->getCursorControl()->setVisible(false);
    _sounds["ingameTheme"]->playLoop();
    while (_device->run() && controller != ESC_QUIT) {
        _driver->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
        _sceneManager->drawAll();
        _gui->drawAll();
        characterInteractions();
        if (_key.IsKeyDown(irr::KEY_ESCAPE)) {
            _escMenu = new EscMenu(_device, _key, _width, _height);
            controller = _escMenu->runEscMenu();
            delete _escMenu;
        }
        _driver->endScene();
    }
    _sounds["ingameTheme"]->stop();
}

void Game::loadPlayers()
{
    for (int i = 0; i < _nb_players; i++) {
        _characters.push_back(std::unique_ptr<Character>(new Character(_pathTextures[i],
            _device, _map->getSpawnAtPosition(i), _key, *_map)));
        loadControls(i);
    }
}

void Game::loadMap()
{
    _map = new Map(_device);
}

void Game::loadCollisions()
{
    for (int i = 0; i < _nb_players; i++)
        _map->setCollision(_characters[i]->getModel());
    if (_nb_players > 1) {
        _characters[0]->setCollision(_characters[1]->getModel());
        _characters[1]->setCollision(_characters[0]->getModel());
    }
}

void Game::loadSounds()
{
    _sounds.emplace("ingameTheme", std::unique_ptr<Music>(new Music("./assets/sounds/ingameTheme.wav")));
}

void Game::loadControls(int player)
{
    if (player == 0) {
        _characters[0]->controls().setForward(irr::KEY_KEY_Z);
        _characters[0]->controls().setBackward(irr::KEY_KEY_S);
        _characters[0]->controls().setLeft(irr::KEY_KEY_Q);
        _characters[0]->controls().setRight(irr::KEY_KEY_D);
        _characters[0]->controls().setPlaceBomb(irr::KEY_SPACE);
    } else if (player == 1) {
        _characters[1]->controls().setForward(irr::KEY_UP);
        _characters[1]->controls().setBackward(irr::KEY_DOWN);
        _characters[1]->controls().setLeft(irr::KEY_LEFT);
        _characters[1]->controls().setRight(irr::KEY_RIGHT);
        _characters[1]->controls().setPlaceBomb(irr::KEY_RCONTROL);
    }
}

void Game::loadEscController()
{
    _escMenuController.emplace(ESC_CONTINUE, std::bind(&Game::escContinue, this));
}

void Game::characterInteractions()
{
    for (int i = 0; i < _nb_players; i++)
        _characters[i]->update();
}

void Game::getCoreVariableValues(Core *core)
{
    _driver = core->getDriver();
    _device = core->getDevice();
    _sceneManager = core->getSceneManager();
    _gui = core->getGui();
    _width = core->getScreenSize().Width;
    _height = core->getScreenSize().Height;
}

void Game::getTextures()
{
    _pathTextures.push_back("./assets/textures/player.bmp");
    _pathTextures.push_back("./assets/textures/player2.bmp");
}

void Game::escContinue()
{
    return;
}
