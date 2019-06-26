/*
** EPITECH PROJECT, 2019
** Music.hpp
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <string>

class Music {
	public:
		Music(const std::string path);
		~Music();
		void play();
		void playLoop();
		void setVolume(float volume);
		void stop();

	private:
        const std::string _path;
		sf::SoundBuffer _buffer;
		sf::Sound _sound;
};

#endif /* !MUSIC_HPP_ */
