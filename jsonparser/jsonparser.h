#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <fstream>
#include <regex>
#include <type_traits>

#include <datastructure/dclist.h>

template<class Type>
class JsonParser
{
    public:
        DCList<Type> * jsonFileToDSList(std::string jsonFile);
        JsonParser();
        void put_int(int value);
        void put_string(std::string value);
    private:
        std::ifstream fileReader;
        DCList<Type> * doubleChainList;
};

template<class Type>
JsonParser<Type>::JsonParser()
{
    this->doubleChainList = new DCList<Type>();
}

template<class Type>
DCList<Type> * JsonParser<Type>::jsonFileToDSList(std::string jsonFile){
    std::string line;

    this->fileReader.open(jsonFile);

    if (this->fileReader.is_open()) {
        while (!this->fileReader.eof()) {

            this->fileReader >> line;
            //std::string subject(line);

            try {
              std::regex regularExpression("(?!\"\\w+\":)(?:(\\d+)|\"(\\w+)\")");
              std::sregex_iterator next(line.begin(), line.end(), regularExpression);
              std::sregex_iterator end;

              while (next != end) {
                std::smatch match = *next;
                std::string str = match.str();
                str.erase(std::remove(str.begin(), str.end(), '"'), str.end());

                if(std::is_same<Type, int>::value){
                    const int val = std::atoi(str.c_str());
                    put_int(val);
                }
                else if(std::is_same<Type, std::string>::value){
                    put_string(str);
                }

                next++;
              }
            } catch (std::regex_error& exeption) {
                std::cout << exeption.what() << std::endl;
            }
        }
    }

    return doubleChainList;
}

template<>
void JsonParser<int>::put_int(int value)
{
    this->doubleChainList->pushFront(value);
}

template<>
void JsonParser<std::string>::put_string(std::string value)
{
    //std::cout << "---" << std::endl;
    this->doubleChainList->pushFront(value);
}

#endif // JSONPARSER_H
