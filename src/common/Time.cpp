/*
** EPITECH PROJECT, 2019
** Time.cpp
** File description:
** Get the elapsed time
*/

#include "../../include/common/Time.hpp"

Clock::Time::Time() : _start(std::chrono::steady_clock::now())
{
}

Clock::Time::Time(std::chrono::nanoseconds const &time) : _time(time)
{
}

Clock::Time::Time::~Time()
{
}

Clock::Time Clock::Time::getElapsedTime()
{
    auto end(std::chrono::steady_clock::now());
    return Clock::Time(end - _start);
}

long int Clock::Time::getAsMicroseconds() const
{
    return (std::chrono::duration_cast<std::chrono::microseconds>(_time).count());
}

long int Clock::Time::getAsMiliseconds() const
{
    return (std::chrono::duration_cast<std::chrono::milliseconds>(_time).count());
}

long int Clock::Time::getAsSeconds() const
{
    return (std::chrono::duration_cast<std::chrono::seconds>(_time).count());
}

