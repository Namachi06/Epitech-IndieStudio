/*
** EPITECH PROJECT, 2019
** Core.cpp
** File description:
** Start the game
*/

#include <iostream>
#include "../include/Core.hpp"
#include "../include/GUI/menu/SplashScreen.hpp"
#include "../include/GUI/menu/MainMenu.hpp"
#include "../include/GUI/Game.hpp"
#include "../include/exception/IndieStudioExceptions.hpp"

Core::Core()
{
    loadDevice();
    _menuController.emplace(MenuController::PLAY, std::bind(&Core::launchGame, this));
    _menuController.emplace(MenuController::MULTI, std::bind(&Core::launchMulti, this));
    _menuController.emplace(MenuController::CONTINUE, std::bind(&Core::launchSaveGame, this));
    _menuController.emplace(MenuController::OPTIONS, std::bind(&Core::launchOptions, this));
    _menuController.emplace(MenuController::EXIT, std::bind(&Core::quitGame, this));
}

Core::~Core()
{
    _device->getSceneManager()->clear();
    _device->drop();
}

void Core::loadDevice()
{
    _device = irr::createDevice(irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(WINDOW_WIDTH, WINDOW_HEIGHT), 32, false, true, false, &_key);
    if (_device == NULL)
        throw ISException::IrrlichtException("Can't load the device");
    _device->getCursorControl()->setVisible(true);
    _device->setWindowCaption(L"SUPER BOMBERMAN");
    _gui = _device->getGUIEnvironment();
    _sceneManager = _device->getSceneManager();
    _driver = _device->getVideoDriver();
    _screensize = _driver->getScreenSize();
    _running = false;
}

void Core::run()
{
    MenuController controller;

    launchSplashScreen();
    if (!_running)
        return;
    controller = launchMenu();
    if (controller != NONE)
        _menuController[controller]();
}

void Core::launchSplashScreen()
{
    SplashScreen splash(this, _key);

    _running = splash.runSplashScreen();
}

MenuController Core::launchMenu()
{
    MainMenu menu(this);

    return menu.runMenu();
}

void Core::launchGame()
{
    Game game(this, _key, 1);

    game.runGame();
}

void Core::launchMulti()
{
    Game game(this, _key, 2);

    game.runGame();
}

void Core::launchSaveGame()
{
    std::cout << "Continue launch successfuly" << std::endl;
}
void Core::launchOptions()
{
    std::cout << "Options launch successfuly" << std::endl;
}

void Core::quitGame()
{
    std::cout << "Game quit successfuly" << std::endl;
}

irr::video::IVideoDriver *Core::getDriver() const
{
    return (_driver);
}

irr::IrrlichtDevice *Core::getDevice() const
{
    return (_device);
}

irr::scene::ISceneManager *Core::getSceneManager() const
{
    return (_sceneManager);
}

irr::gui::IGUIEnvironment *Core::getGui() const
{
    return (_gui);
}

irr::core::dimension2du Core::getScreenSize() const
{
    return (_screensize);
}
