#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    //fill the array with random numbers
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //test the copy constructor and copy assignment operator
    Array<int> copy1 = numbers;
    Array<int> copy2(numbers);

    std::cout << "numbers[" << numbers.size() << "]" << std::endl;
    std::cout << "copy1[" << copy1.size() << "]" << std::endl;
    std::cout << "copy2[" << copy2.size() << "]" << std::endl;
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "The template array differs at " << i << "\n" << mirror[i] << "!=" << numbers[i] << std::endl;
        }
        if (mirror[i] != copy1[i])
        {
            std::cerr << "Copy assigned array differs at " << i << "\n" << mirror[i] << " != " << copy1[i] << std::endl;
        }
        if (mirror[i] != copy2[i])
        {
            std::cerr << "Copy constructed array differs at " << i << "\n" << mirror[i] << " != " << copy2[i] << std::endl;
        }
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete [] mirror;

    Array<std::string> strs(2);
    strs[0] = "Zero";
    strs[1] = "One";
    std::cout << strs[0] << strs[1] << std::endl;

    // const Array<int> constArr(1);
    // std::cout << constArr[0] << std::endl;
    return 0;
}