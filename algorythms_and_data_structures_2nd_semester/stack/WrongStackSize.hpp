#ifndef STACK_BELOSHITSKIY_DR_WRONGSTACKSIZE_HPP
#define STACK_BELOSHITSKIY_DR_WRONGSTACKSIZE_HPP

#include <exception>

class WrongStackSize: public std::exception {
public:
    const char *what() const noexcept override;
};

const char *WrongStackSize::what() const noexcept
{
    return "WrongStackSize\n";
}

#endif //STACK_BELOSHITSKIY_DR_WRONGSTACKSIZE_HPP
