#ifndef BINARY_TREE_BELOSHITSKIY_DR_STACKUNDERFLOW_HPP
#define BINARY_TREE_BELOSHITSKIY_DR_STACKUNDERFLOW_HPP

#include <exception>

class StackUnderflow: public std::exception {
public:
    const char *what() const noexcept override;
};

const char *StackUnderflow::what() const noexcept
{
    return "StackUnderflow\n";
}

#endif //BINARY_TREE_BELOSHITSKIY_DR_STACKUNDERFLOW_HPP
