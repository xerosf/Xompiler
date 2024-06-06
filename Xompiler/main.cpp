#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    string fileName;
    string line;

    try {
        string argument = argv[1];

        if (argument.find(".xro")) {
            int pos = argument.find(".xro");
            fileName = argument.substr(0, pos);
        }
        else if (argument.find(".xro") == string::npos) {
            fileName = argument;
        }
        else
            throw(argument);
    }
    catch (string argument) {
        cout << "Given argument: '" << argument << ".xro' was not found in directory!";
    }

    ifstream file((fileName + ".xro"));

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    return 0;
}