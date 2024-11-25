#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char **argv) {
    if (argc <= 1)
        return std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0;
    for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
            std::cout << arg;
            if (i < argc - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    return 0;
}