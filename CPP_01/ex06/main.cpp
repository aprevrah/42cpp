#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;
    if (argc != 2) {
        std::cout << "Need exactly one argument (debug, info, warning, error)." << std::endl;
        return 1;
    }
    std::string level = argv[1];

	std::string levelArr[4] = {"debug", "info", "warning", "error"};

	int		i = -1;
	while (++i < 4) {
		if (levelArr[i] == level)
			break;
	}
	switch (i)
	{
	case 0:
		harl.complain("debug");
	case 1:
		harl.complain("info");
	case 2:
		harl.complain("warning");
	case 3:
		harl.complain("error");
		break;
	default:
    	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

    return 0;
}
