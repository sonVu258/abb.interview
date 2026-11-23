#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
    const int min_filmrequired = 9;
    const int directors_column = 4;
    std::ifstream file("IMDb_Top_700_Movies_2026.csv");
    if (!file.is_open()) {
        std::cerr << "Cannot open file\n";
        return 1;
    }
    std::string line;
    std::getline(file, line);   
    std::map<std::string, int> counts;

    while(std::getline(file, line)) {
        std::vector<std::string> fields;
        std::stringstream ss(line);
        std::string field;
        while(std::getline(ss, field, ',')) {
            fields.push_back(field);
        }
        if(fields.size() <= directors_column) continue;
        std::string director = fields[directors_column];
        counts[director]++;  

    }
    for (const auto& [name, n] : counts) {
      if (n >= min_filmrequired) {
          std::cout << "Director: " << name << " with " << n << " movies\n";
      }
    }
    return 0;
}