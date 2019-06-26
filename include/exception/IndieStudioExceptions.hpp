/*
** EPITECH PROJECT, 2019
** IndieStudioExceptions.hpp
** File description:
** Indie Studio error exceptions header
*/

#ifndef INDIESTUDIOEXCEPTIONS_HPP_
#define INDIESTUDIOEXCEPTIONS_HPP_

#include <string>
#include <exception>

namespace ISException
{
    class IndieStudioExceptions : public std::exception {
        public:
            IndieStudioExceptions(std::string const &e);
            ~IndieStudioExceptions();
            virtual const char *what() const throw();

        private:
            std::string _errorMessage;
    };

    class IrrlichtException : public IndieStudioExceptions {
        public:
            IrrlichtException(std::string const &errorMessage);
            ~IrrlichtException();
    };

    class SfmlAudioException : public IndieStudioExceptions {
        public:
            SfmlAudioException(std::string const &errorMessage);
            ~SfmlAudioException();
    };

    class RuntimeException : public IndieStudioExceptions {
        public:
            RuntimeException(std::string const &errorMessage);
            ~RuntimeException();
    };
};



#endif /* !INDIESTUDIOEXCEPTIONS_HPP_ */
