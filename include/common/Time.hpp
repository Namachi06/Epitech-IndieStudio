/*
** EPITECH PROJECT, 2019
** Time.hpp
** File description:
** Handle clock, virtual time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <chrono>

namespace Clock
{
    class Time {
        public:
            Time();
            Time(std::chrono::nanoseconds const &time);
            ~Time();
            Time getElapsedTime();
            long int getAsMicroseconds() const;
            long int getAsMiliseconds() const;
            long int getAsSeconds() const;
        private:
            std::chrono::time_point<std::chrono::steady_clock> _start;
            std::chrono::nanoseconds _time;
    };
};


#endif /* !TIME_HPP_ */
