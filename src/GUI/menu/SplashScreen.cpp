/*
** EPITECH PROJECT, 2019
** SplashScreen.cpp
** File description:
** Splash screen
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "../../../include/GUI/menu/SplashScreen.hpp"

SplashScreen::SplashScreen(Core *core, KeyboardEvent &key) : _key(key)
{
    getCoreVariableValues(core);
    loadSplashScreen();
}

SplashScreen::~SplashScreen()
{
}

bool SplashScreen::runSplashScreen()
{
    bool running;

    _sounds["startMenu"]->playLoop();
    while ((running = _device->run()) == true) {
        _driver->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
         if (_key.IsKeyDown(irr::KEY_SPACE)) {
            return exitSplashScreen();
         }
        _driver->draw2DImage(_splashImages[0],
            irr::core::rect<irr::s32>(0, 0, _width, _height),
            irr::core::rect<irr::s32>(0, 0, _width, _height));
        if (_clock.getElapsedTime().getAsSeconds() % 2 == 0)
            _driver->draw2DImage(_splashImages[1],
            irr::core::rect<irr::s32>(0, 0, _width, _height),
            irr::core::rect<irr::s32>(0, 0, _width, _height));
        _gui->drawAll();
        _driver->endScene();
    }
    return (running);
}

bool SplashScreen::exitSplashScreen()
{
    _sounds["startMenu"]->stop();
    _sounds["spacePressed"]->play();
    _key.resetKey();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return (true);
}

void SplashScreen::loadSplashScreen()
{
    _splashImages.push_back(_driver->getTexture("./assets/images/splash_screen.png"));
    _splashImages.push_back(_driver->getTexture("./assets/images/splash_screen2.png"));
    _sounds.emplace("spacePressed", std::unique_ptr<Music>(new Music("./assets/sounds/pressStart.wav")));
    _sounds.emplace("startMenu", std::unique_ptr<Music>(new Music("./assets/sounds/startScreen.wav")));
}

void SplashScreen::getCoreVariableValues(Core *core)
{
    _driver = core->getDriver();
    _device = core->getDevice();
    _sceneManager = core->getSceneManager();
    _gui = core->getGui();
    _width = core->getScreenSize().Width;
    _height = core->getScreenSize().Height;
}

