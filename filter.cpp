#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("IMDb_Top_700_Movies_2026.csv");
    if (!file.is_open()) {
        std::cerr << "Cannot open file\n";
        return 1;
    }
    std::string line;
    for (int i = 0; i < 3 && std::getline(file, line); ++i) {
        std::cout << line << "\n";   // in header + 2 dòng đầu
    }
    return 0;
}