#include <iostream>
#include "StackArray.hpp"

bool checkBalanceBrackets(const std::string &text, int maxDeep = 30);

bool testCheckBalanceBrackets();

bool getPostfixFromInfix(const std::string &infix, std::string &postfix, size_t stackSize = 30);

double evaluatePostfix(const std::string &infix, size_t stackSize = 30);

int main()
{
    testCheckBalanceBrackets();
    std::cout << "Checking Infix to Postfix conversion..." << std::endl;
    {
        std::string infix = "4*(6-3)+(8-6)/2";
        std::string postfix;
        getPostfixFromInfix(infix, postfix);
        std::cout << "Postfix: " << postfix << '\t'
                  << "Result: " << evaluatePostfix(postfix) << std::endl;
    }

    {
        std::string infix = "((4*(6-3)+(8-6)/2))";
        std::string postfix;
        getPostfixFromInfix(infix, postfix);
        std::cout << "Postfix: " << postfix << '\t'
                  << "Result: " << evaluatePostfix(postfix) << std::endl;
    }

    {
        std::string infix = "(45-21)*(3-4)+5";
        std::string postfix;
        getPostfixFromInfix(infix, postfix);
        std::cout << "Postfix: " << postfix << '\t'
                  << "Result: " << evaluatePostfix(postfix) << std::endl;
    }

    {
        std::string infix = "9*3-(43+31)/2";
        std::string postfix;
        getPostfixFromInfix(infix, postfix);
        std::cout << "Postfix: " << postfix << '\t'
                  << "Result: " << evaluatePostfix(postfix) << std::endl;
    }

    std::cout << std::endl << "Checking move function" << std::endl;
    {
        StackArray<int> first_stack;
        first_stack.push(32);
        first_stack.push(11);
        first_stack.push(55);
        StackArray<int> second_stack = std::move(first_stack);
        first_stack = std::move(second_stack);
    }

    std::cout << std::endl << "Checking exceptions" << std::endl;
    {
        try {
            StackArray<int> stack(0);
        } catch (const WrongStackSize &err) {
            std::cerr << err.what();
        }
        try {
            StackArray<int> stack;
            stack.pop();
        } catch (const StackUnderflow &err) {
            std::cerr << err.what();
        }
        try {
            StackArray<int> stack(2);
            stack.push(98);
            stack.push(43);
            stack.push(3);
        } catch (const StackOverflow &err) {
            std::cerr << err.what();
        }
    }

}

bool checkBalanceBrackets(const std::string &text, int maxDeep)
{
    StackArray<char> stack(maxDeep);
    for (const char i : text) {
        switch (i) {
        case '(':
            stack.push(i);
            break;
        case '[':
            stack.push(i);
            break;
        case '{':
            stack.push(i);
            break;
        case ')':
            if (!stack.isEmpty()) {
                char t = stack.pop();
                if (t != '(') {
                    return false;
                }
            } else {
                return false;
            }
            break;
        case ']':
            if (!stack.isEmpty()) {
                char t = stack.pop();
                if (t != '[') {
                    return false;
                }
            } else {
                return false;
            }
            break;
        case '}':
            if (!stack.isEmpty()) {
                char t = stack.pop();
                if (t != '{') {
                    return false;
                }
            } else {
                return false;
            }
            break;
        }
    }
    return stack.isEmpty();
}

bool testCheckBalanceBrackets()
{
    std::cout << "Checking balance brackets..." << std::endl;
    std::string text00 = "ok ";
    std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "right" : "wrong") << std::endl;
    std::string text01 = "( ) ok ";
    std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "right" : "wrong") << std::endl;
    std::string text02 = "( ( [] ) ) ok ";
    std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "right" : "wrong") << std::endl;
    std::string text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) ok";
    std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "right" : "wrong") << std::endl;
    std::string text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
    std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "right" : "wrong") << std::endl;
    std::string text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
    std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "right" : "wrong") << std::endl;
    std::string text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
    std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << std::endl;
    return true;
}

bool getPostfixFromInfix(const std::string &infix, std::string &postfix, size_t stackSize)
{
    StackArray<char> stack(stackSize);
    for (const char temp : infix) {
        if (temp == '(') {
            stack.push(temp);
        } else if (temp == ')') {
            if (!stack.isEmpty()) {
                char c = stack.pop();
                while (c != '(') {
                    postfix += c;
                    if (!stack.isEmpty()) {
                        c = stack.pop();
                    } else {
                        break;
                    }
                }
            }
        } else if (temp == '+' || temp == '-') {
            if (!stack.isEmpty()) {
                char c = stack.pop();
                if (c == '(') {
                    stack.push(c);
                }
                while (c != '(' && (c == '*' || c == '/' || c == '-' || c == '+')) {
                    postfix += c;
                    if (!stack.isEmpty()) {
                        c = stack.pop();
                    } else {
                        break;
                    }
                }
            }
            stack.push(temp);
        } else if (temp == '*' || temp == '/') {
            if (!stack.isEmpty()) {
                char c = stack.pop();
                if (c == '+' || c == '-') {
                    stack.push(c);
                }
                while (c != '(' && (c == '*' || c == '/')) {
                    postfix += c;
                    if (!stack.isEmpty()) {
                        c = stack.pop();
                        if (c == '+' || c == '-') {
                            stack.push(c);
                        }
                    } else {
                        return false;
                    }
                }
            }
            stack.push(temp);
        } else {
            postfix += temp;
        }
    }
    char c;
    while (!stack.isEmpty()) {
        c = stack.pop();
        if (c != '+' && c != '/' && c != '*' && c != '-') {
            return false;
        }
        postfix += c;
    }
    return true;
}

double evaluatePostfix(const std::string &infix, size_t stackSize)
{
    double result = 0;
    StackArray<int> stack(stackSize);
    for (char temp : infix) {
        switch (temp) {
        case '+':
            stack.push(stack.pop() + stack.pop());
            break;
        case '-': {
            double right = stack.pop();
            double left = stack.pop();
            stack.push(left - right);
            break;
        }
        case '*':
            stack.push(stack.pop() * stack.pop());
            break;
        case '/': {
            double right = stack.pop();
            double left = stack.pop();
            stack.push(left / right);
            break;
        }
        default:
            stack.push(temp - '0');
        }
    }
    result = stack.pop();
    return result;
}
