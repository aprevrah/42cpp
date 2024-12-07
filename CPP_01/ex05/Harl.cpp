#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
	std::cout << "DEBUG: The coffee machine didn't start this morning. I pressed the button three times. THREE TIMES! What does it want, a love letter?" << std::endl;
}

void Harl::info(void) {
	std::cout << "INFO: After some deep soul-searching (and frantic Googling), I realized the water tank was empty. Who designs a machine that can't even warn me?" << std::endl;
}

void Harl::warning(void) {
	std::cout << "WARNING: I filled the water tank, but now it's making ominous gurgling noises. This feels like the calm before the caffeinated storm." << std::endl;
}

void Harl::error(void) {
	std::cout << "ERROR: The coffee machine has officially given up. No coffee. No hope. Just me, staring into the void and wondering why I even bother." << std::endl;
}

void Harl::complain(std::string level) {
    static struct pair{
        std::string level;
        void (Harl::*func)();
    }	 
	functionArray[] = {
        {"debug", &Harl::debug},
        {"info", &Harl::info},
        {"warning", &Harl::warning},
        {"error", &Harl::error}
    };

    for (int i = 0; i < 4; i++) {
        if (functionArray[i].level == level) {
            (this->*(functionArray[i].func))();
            return;
        }
    }
    std::cout << "Error: Invalid level '" << level << "'." << std::endl;
}