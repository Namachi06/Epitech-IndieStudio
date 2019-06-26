/*
** EPITECH PROJECT, 2019
** IndieStudioExceptions.cpp
** File description:
** Indie Studio errors exceptions
*/

#include "../../include/exception/IndieStudioExceptions.hpp"

ISException::IndieStudioExceptions::IndieStudioExceptions(std::string const &e) : _errorMessage(e)
{
}

ISException::IndieStudioExceptions::~IndieStudioExceptions()
{
}

const char *ISException::IndieStudioExceptions::what() const throw()
{
    return _errorMessage.c_str();
}

// Irrlicht exception
ISException::IrrlichtException::IrrlichtException(std::string const &errorMessage) : IndieStudioExceptions(errorMessage)
{
}

ISException::IrrlichtException::~IrrlichtException()
{
}

// SFML Audio Exception
ISException::SfmlAudioException::SfmlAudioException(std::string const &errorMessage) : IndieStudioExceptions(errorMessage)
{
}

ISException::SfmlAudioException::~SfmlAudioException()
{
}

// runtime Excetpion
ISException::RuntimeException::RuntimeException(std::string const &errorMessage) : IndieStudioExceptions(errorMessage)
{
}

ISException::RuntimeException::~RuntimeException()
{
}
