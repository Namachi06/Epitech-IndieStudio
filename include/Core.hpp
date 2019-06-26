/*
** EPITECH PROJECT, 2019
** Core.hpp
** File description:
** Core header
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#include <irrlicht.h>
#include <SFML/Audio.h>
#include <map>
#include <functional>
#include "../include/event/KeyboardEvent.hpp"

enum MenuController
{
    PLAY,
    MULTI,
    CONTINUE,
    OPTIONS,
    EXIT,
    NONE
};

class Core {
    public:
        Core();
        ~Core();
        void loadDevice();
        void run();
        void launchSplashScreen();
        MenuController launchMenu();
        void launchGame();
        void launchMulti();
        void launchSaveGame();
        void launchOptions();
        void quitGame();

        irr::video::IVideoDriver *getDriver() const;
        irr::IrrlichtDevice *getDevice() const;
        irr::scene::ISceneManager *getSceneManager() const;
        irr::gui::IGUIEnvironment *getGui() const;
        irr::core::dimension2du getScreenSize() const;
        KeyboardEvent &getKeyEvent() const;

    private:
        irr::video::IVideoDriver *_driver;
        irr::IrrlichtDevice *_device;
        irr::scene::ISceneManager *_sceneManager;
        irr::gui::IGUIEnvironment *_gui;
        irr::core::dimension2du _screensize;
        std::map<MenuController, std::function<void()>> _menuController;
        KeyboardEvent _key;
        bool _running;
};

#endif /* !CORE_HPP_ */
