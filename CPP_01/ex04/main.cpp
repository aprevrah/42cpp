#include <string>
#include <iostream>
#include <fstream>

bool makeDotReplace(const std::string& filename, const std::string& findStr, const std::string& replaceStr) {
    if (findStr.empty()) {
        std::cerr << "Error: need a string to find" << std::endl;
    }
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file " << filename << std::endl;
        return false;
    }
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        inputFile.close();
        std::cerr << "Error: Could not create output file " << outputFilename << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string::size_type pos = 0;
        while ((pos = line.find(findStr, pos)) != std::string::npos) {
            line.erase(pos, findStr.length()); // replace(pos, findStr.length(), replaceStr);
            line.insert(pos, replaceStr);
            pos += replaceStr.length();
        }
        outputFile << line << '\n';
    }
    inputFile.close();
    outputFile.close();
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (!makeDotReplace(filename, s1, s2))
        return 1;
    return 0;
}