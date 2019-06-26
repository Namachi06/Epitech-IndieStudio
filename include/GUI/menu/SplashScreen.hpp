/*
** EPITECH PROJECT, 2019
** SplashScreen.hpp
** File description:
** Splash screen
*/

#ifndef SPLASHSCREEN_HPP_
#define SPLASHSCREEN_HPP_

#include <vector>
#include <map>
#include <memory>
#include "../../Core.hpp"
#include "../../../include/sound/Music.hpp"
#include "../../common/Time.hpp"
#include "../../event/KeyboardEvent.hpp"

class SplashScreen {
	public:
		SplashScreen(Core *core, KeyboardEvent &key);
		~SplashScreen();
        bool runSplashScreen();
        void loadSplashScreen();
        bool exitSplashScreen();
        void getCoreVariableValues(Core *core);
	private:
        std::vector<irr::video::ITexture *> _splashImages;
        std::map<std::string, std::unique_ptr<Music>> _sounds;
        irr::video::IVideoDriver *_driver;
        irr::IrrlichtDevice *_device;
        irr::scene::ISceneManager *_sceneManager;
        irr::gui::IGUIEnvironment *_gui;
        Clock::Time _clock;
        KeyboardEvent &_key;
        int _width;
        int _height;
};

#endif /* !SPLASHSCREEN_HPP_ */
