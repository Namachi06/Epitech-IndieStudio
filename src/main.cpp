/*
** EPITECH PROJECT, 2019
** Main.cpp
** File description:
** Main program
*/

#include <iostream>
#include "../include/exception/IndieStudioExceptions.hpp"
#include "../include/Core.hpp"
#include "../include/GUI/menu/MainMenu.hpp"
#include "../include/GUI/menu/EscMenu.hpp"
#include "../include/GUI/Map.hpp"
#include "../include/GUI/Game.hpp"

int main(void)
{
    try {
        Core core;
        core.run();
    } catch(ISException::IndieStudioExceptions const &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}

