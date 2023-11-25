#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

bool checkOutput(const std::string& output, const std::string& check = "") {
    try {
        std::ifstream raw(output);
        json data = json::parse(raw);
        if(check == "stdout")
            std::cout << std::setw(4) << data << std::endl;
        else if (!check.empty()) {
            std::ofstream formatted(check);
            formatted << std::setw(4) << data << std::endl;
        }
    }
    catch (...) {
        return false;
    }
    return true;
}

int main() {
    if(!checkOutput("example.json", "pretty.json"))
        std::cerr << "output is not a valid json" << std::endl;

    return 0;
}