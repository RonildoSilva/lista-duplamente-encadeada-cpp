#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <regex>

#include "template/object.hpp"
#include "datastructure/node.hpp"
#include "datastructure/dclist.h"
#include "jsonparser/jsonparser.h"

using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    DCList<int> * doubleChainList;
    JsonParser<int> * jPaser = new JsonParser<int>();

    //DCList<float> * doubleChainList;
    //JsonParser<float> * jPaser = new JsonParser<float>();

    //DCList<string> * doubleChainList;
    //JsonParser<string> * jPaser = new JsonParser<string>();

    doubleChainList = jPaser->jsonFileToDSList("content.json");

    doubleChainList->show();
    //return a.exec();

    return 0;
}
