#ifndef LL_PARSER_PRODUCTION_H
#define LL_PARSER_PRODUCTION_H
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

class production
{
public:
    string left;
    vector<vector<string>> right;
    production(const string &str);
    void print();
    void insert(const vector<string> &nodes);
    bool includeEpsilon();
    string toString() const;

};
#endif //LL_PARSER_PRODUCTION_H
