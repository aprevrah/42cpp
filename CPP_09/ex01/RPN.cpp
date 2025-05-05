#include "RPN.hpp"

RPN::RPN() : _expr(""), _stack() {}
RPN::RPN(std::string expr) : _expr(expr), _stack() {}
RPN::RPN(const RPN &src) : _expr(src._expr), _stack(src._stack) {}
RPN::~RPN() {}
RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        _expr = rhs._expr;
        _stack = rhs._stack;
    }
    return *this;
}

void RPN::doOper(char opperator)
{
    if (_stack.size() < 2)
    {
        throw std::invalid_argument("Not enough operands");
    }
    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();

    switch (opperator)
    {
    case '+':
        _stack.push(left + right);
        break;
    case '-':
        _stack.push(left - right);
        break;
    case '*':
        _stack.push(left * right);
        break;
    case '/':
        if (right == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        _stack.push(left / right);
        break;
    default:
        throw std::invalid_argument("Invalid operator");
    }
}

int RPN::evaluate()
{
    for (size_t i = 0; i < _expr.length(); i++)
    {
        //std::cout << _expr[i];
        if (isdigit(_expr[i]))
        {
            _stack.push(_expr[i] - '0');
        }
        else if (_expr[i] == ' ')
        {
            continue;
        }
        else
        {
            doOper(_expr[i]);
        }
    }
    if (_stack.size() != 1)
    {
        throw std::invalid_argument("Too many operands");
    }
    return _stack.top();
}