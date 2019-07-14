#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <fstream>
#include <regex>

#include <datastructure/dclist.h>

template<class Type>
class JsonParser
{
    public:
        DCList<Type> * jsonFileToDSList(std::string jsonFile);
    private:
        std::ifstream fileReader;
};

template<class Type>
DCList<Type> * JsonParser<Type>::jsonFileToDSList(std::string jsonFile){
    DCList<Type> * doubleChainList = new DCList<Type>();
    std::string line;

    this->fileReader.open(jsonFile);

    if (this->fileReader.is_open()) {
        while (!this->fileReader.eof()) {

            this->fileReader >> line;
            std::string subject(line);

            try {
              std::regex re("(?!\"\\w+\":)(?:(\\d+)|\"(\\w+)\")");
              std::sregex_iterator next(subject.begin(), subject.end(), re);
              std::sregex_iterator end;
              while (next != end) {
                std::smatch match = *next;
                std::string str = match.str();
                str.erase(std::remove(str.begin(), str.end(), '"'), str.end());

                doubleChainList->pushFront(str);
                next++;
              }
            } catch (std::regex_error& e) {
              // Syntax error in the regular expression
            }
        }
    }

    return doubleChainList;
}

#endif // JSONPARSER_H
