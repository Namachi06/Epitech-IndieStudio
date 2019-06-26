/*
** EPITECH PROJECT, 2019
** Music.cpp
** File description:
** Music
*/

#include <iostream>
#include <unistd.h>
#include "../../include/sound/Music.hpp"
#include "../../include/common/Time.hpp"
#include "../../include/exception/IndieStudioExceptions.hpp"

Music::Music(std::string path) : _path(path)
{
    if (!_buffer.loadFromFile(_path))
        throw ISException::SfmlAudioException("Can't load audio " + _path);
    _sound.setBuffer(_buffer);
    std::cout << "Music Ready" << std::endl;
}

Music::~Music()
{
}

void Music::play()
{
    _sound.play();
}

void Music::playLoop()
{
    _sound.setLoop(true);
    _sound.play();
}

void Music::setVolume(float volume)
{
    if (_sound.getStatus() != _sound.Playing || _sound.getVolume() <= 0)
        return;
    _sound.setVolume(volume);
}

void Music::stop()
{
    _sound.stop();
}
