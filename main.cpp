#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <regex>

#include "template/object.hpp"
#include "datastructure/node.hpp"
#include "datastructure/dclist.h"

using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    DCList<string> * doubleChainList = new DCList<string>();

    ifstream myReadFile;
    myReadFile.open("content.json");
    string output;

    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {

            myReadFile >> output;
            std::string subject(output);

            try {
              std::regex re("(?!\"\\w+\":)(?:(\\d+)|\"(\\w+)\")");
              std::sregex_iterator next(subject.begin(), subject.end(), re);
              std::sregex_iterator end;
              while (next != end) {
                std::smatch match = *next;
                //std::cout << match.str() << "\n";
                doubleChainList->pushFront(match.str());
                next++;
              }
            } catch (std::regex_error& e) {
              // Syntax error in the regular expression
            }
        }
    }

    doubleChainList->show();
    //return a.exec();

    return 0;
}
