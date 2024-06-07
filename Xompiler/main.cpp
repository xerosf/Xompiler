#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    string fileName;
    string line;
    vector<string> keys;

    if (argc < 2) {
        cout << "\033[1;31m" << "[XCC Error] " << "\033[0m" << "Source file not specified!" << endl;
        return 1;
    }

    try {
        string argument = argv[1];

        if (argument == "--help") {
            cout << "\033[1;32m" << "[XCC v0.1] " << "\033[0m" << "Built for Windows x64.\n" << endl;
            cout << "\033[1;33m" << "XeroScript " << "\033[0m" << "is a high level programming language, created to run through an interpreter written purely in C++. This started as a project for me to learn how high level programming languages are read and either interpreted or compiled into a low level language which is then executed by the CPU. I hope to and improve my programming skills through this project and learn more about how computers work." << "\033[1;31m" << " Thank you <3" << "\033[0m" << endl;
            return 0;
        }
        if (argument == "--version") {
            cout << "\033[1;32m" << "[XCC v0.1] " << "\033[0m" << "07/06/2024" << endl;
            cout << "\nBuilt for Windows x64." << endl; // Change
            return 0;
        }
        if (argument.rfind(".xro") == argument.length() - 4) {
            fileName = argument.substr(0, argument.length() - 4);
        }
        else {
            fileName = argument;
        }
    }
    catch (const exception& e) {
        cout << "\033[1;31m" << "[XCC Error] " << "\033[0m" << "Invalid argument: " << e.what() << endl;
        return 1;
    }

    ifstream file((fileName + ".xro"));
    if (!file.is_open()) {
        cout << "\033[1;31m" << "[XCC Error] " << "\033[0m" << "Failed to open file: " << fileName << ".xro" << endl;
        return 1;
    }

    cout << "\033[1;32m" << "[XCC v0.1] " << "\033[0m" << "Run 'xcc --help' for more information." << endl;

    while (getline(file, line)) {
        istringstream iss(line);
        string word;

        iss >> word;

        string restOfLine;
        while (iss >> word) {
            restOfLine += (restOfLine.empty() ? "" : " ") + word;
        }

        keys.push_back(restOfLine);
    }

    for (const auto& key : keys) {
        string value = key.substr(1, key.size() - 2);
        cout << value << endl;
    }

    return 0;
}