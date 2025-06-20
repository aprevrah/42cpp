#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Expected one arg" << std::endl;
        return 1;
    }
        
    std::string expr = argv[1];
    RPN RPN(expr);
    int result = 0;
    try {
        result = RPN.evaluate();
        std::cout << "result:" << result << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}