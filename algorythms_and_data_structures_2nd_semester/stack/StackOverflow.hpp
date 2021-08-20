#ifndef STACK_BELOSHITSKIY_DR_STACKOVERFLOW_HPP
#define STACK_BELOSHITSKIY_DR_STACKOVERFLOW_HPP

#include <exception>

class StackOverflow: public std::exception {
public:
    const char *what() const noexcept override;
};

const char *StackOverflow::what() const noexcept
{
    return "StackOverflow\n";
}

#endif //STACK_BELOSHITSKIY_DR_STACKOVERFLOW_HPP
