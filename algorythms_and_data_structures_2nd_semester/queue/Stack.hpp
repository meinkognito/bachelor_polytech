#ifndef BINARY_TREE_BELOSHITSKIY_DR_STACK_HPP
#define BINARY_TREE_BELOSHITSKIY_DR_STACK_HPP

template<class T>
class Stack {
public:
    virtual ~Stack() = default;

    virtual void push(const T &e) = 0;

    virtual T pop() = 0;

    virtual bool isEmpty() = 0;
};

#endif //BINARY_TREE_BELOSHITSKIY_DR_STACK_HPP
