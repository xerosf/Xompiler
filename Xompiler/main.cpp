#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    int pos = 0;
    string fileName;
    string line;

    try {
        string argument = argv[1];

        if (argument.find(".xro")) {
            int pos = argument.find(".xro");
            string fileName = argument.substr(0, pos);
        }
        else if (argument.find(".xro") == string::npos) {
            string fileName = argument;
        }
        else
            throw(argument);
    }
    catch (string argument) {
        cout << "Given argument: '" << argument << ".xro' was not found in directory!";
    }

    ifstream file(fileName + ".xro");

    cout << "Opened" << endl;

    while (getline(file, line)) {
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return 1;
        }
    }

    file.close();

    return 0;
}