/*
** EPITECH PROJECT, 2019
** MainMenu.cpp
** File description:
** Launch the main menu
*/

#include <iostream>
#include "../../../include/GUI/menu/MainMenu.hpp"

MainMenu::MainMenu(Core *core)
{
    getCoreVariableValues(core);
    loadImages();
    createButtons();
    std::cout << "MainMenu Ready" << std::endl;
}

MainMenu::~MainMenu()
{
    if (!_menuButtons.empty())
        destroyButtons();
    if (!_menuImages.empty())
        _menuImages.clear();
}

MenuController MainMenu::runMenu()
{
    MenuController controller = NONE;
    Music music("./assets/sounds/mainMenuTheme.wav");

    music.playLoop();
    while (_device->run() && controller == MenuController::NONE) {
        _driver->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
        _driver->draw2DImage(_menuImages[0],
            irr::core::rect<irr::s32>(0, 0, _width, _height),
            irr::core::rect<irr::s32>(0, 0, _width, _height));
        _gui->drawAll();
        controller = buttonsHandler();
        _driver->endScene();
    }
    music.stop();
    return (controller);
}

MenuController MainMenu::buttonsHandler()
{
    std::vector<irr::gui::IGUIButton *>::iterator it = _menuButtons.begin();

    for (int i = 0; it != _menuButtons.end(); it++, i++) {
        if ((*it)->isPressed()) {
            (*it)->setPressed(false);
            return ((MenuController)i);
        }
    }
    return (MenuController::NONE);
}

void MainMenu::createButtons()
{
    int i = 0;
    int y = _height / 2.85;
    int x = _width / 1.5;

    while (i < NB_BUTTONS) {
        y += _height / 9.7;
        _menuButtons.push_back(_gui->addButton(irr::core::rect<irr::s32>
            (x - _width / 2.2, y - _height / 15.5, _width / 2.2, y)));
        _menuButtons[i]->setImage(_menuImages[i + 1]);
        _menuButtons[i]->setScaleImage();
        _menuButtons[i]->setIsPushButton();
        i++;
    }
}

void MainMenu::destroyButtons()
{
    std::vector<irr::gui::IGUIButton *>::iterator it = _menuButtons.begin();

    for (; it != _menuButtons.end(); it++)
        (*it)->remove();
    _menuButtons.clear();
}

void MainMenu::loadImages()
{
    _menuImages.push_back(_driver->getTexture("./assets/images/menu_backg.jpg"));
    _menuImages.push_back(_driver->getTexture("./assets/images/PLAY.png"));
    _menuImages.push_back(_driver->getTexture("./assets/images/MULTI.png"));
    _menuImages.push_back(_driver->getTexture("./assets/images/CONTINUE.png"));
    _menuImages.push_back(_driver->getTexture("./assets/images/OPTIONS.png"));
    _menuImages.push_back(_driver->getTexture("./assets/images/EXIT.png"));
}

void MainMenu::getCoreVariableValues(Core *core)
{
    _driver = core->getDriver();
    _device = core->getDevice();
    _sceneManager = core->getSceneManager();
    _gui = core->getGui();
    _width = core->getScreenSize().Width;
    _height = core->getScreenSize().Height;
}
