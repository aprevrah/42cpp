#include <iostream>
#include <string>
#include <stack>

int doOper(char opperator, std::stack<int>& stack) {
    int f = stack.top(); stack.pop();
    int s = stack.top(); stack.pop();
    
    if (opperator == '+')
        stack.push(f + s);
    else if (opperator == '-')
        stack.push(f - s);
    else if (opperator == '*')
        stack.push(f * s);
    else if (opperator == '/')
        stack.push(f / s);
    else
        return 1;
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 1)
        std::cerr << "Expected one arg" << std::endl;

    std::stack<int> stack;
    std::string expr(argv[1]);
    for (size_t i = 0; i < expr.length(); i++) {
        std::cout << expr[i];
        if (isdigit(expr[i])) {
            stack.push(expr[i] - '0');
        }
        else if (expr[i] == ' ') {
            continue;
        }
        else {
            doOper(expr[i], stack);
        }
        //std::cout << stack.top();
    }
    std::cout << "result:" << stack.top();
}