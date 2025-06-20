#pragma once
#include <string>
#include <stack>
#include <iostream>
#include <stdexcept>

class RPN
{
    private:
        std::string _expr;
        std::stack<int> _stack;
    public:
        RPN();
        RPN(std::string expr);
        RPN(const RPN &src);
        ~RPN();
        RPN &operator=(const RPN &rhs);

        void doOper(char opperator);
        int evaluate();
            
};