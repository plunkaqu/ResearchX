#include <iostream>
#include <fstream>
#include <string>

// Example: Check if the file contains certain keywords
bool detectAI(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("AI") != std::string::npos || line.find("neural") != std::string::npos) {
            return true; // Found keywords
        }
    }
    
    return false; // No keywords found
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }
    
    std::string filePath = argv[1];
    bool result = detectAI(filePath);
    std::cout << (result ? "AI Detected" : "No AI Detected") << std::endl;
    return 0;
}
