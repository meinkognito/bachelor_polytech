#ifndef STACK_BELOSHITSKIY_DR_STACKUNDERFLOW_HPP
#define STACK_BELOSHITSKIY_DR_STACKUNDERFLOW_HPP

#include <exception>

class StackUnderflow: public std::exception {
public:
    const char *what() const noexcept override;
};

const char *StackUnderflow::what() const noexcept
{
    return "StackUnderflow\n";
}

#endif //STACK_BELOSHITSKIY_DR_STACKUNDERFLOW_HPP
