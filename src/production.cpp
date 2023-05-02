#include "production.h"

production::production(const string &str) {
    left = str;
    right.clear();
}

void production::print() {
    cout << left << "==>";
    for(const auto & i : right[0])
    {
        cout << ' ' << i;
    }

    for(size_t i = 1; i < right.size(); i++)
    {
        cout << " |";
        for(size_t j = 0; j < right[i].size(); j++)
        {
            cout << ' ' << right[i][j];
        }
    }
    cout << endl;
}

string production::toString() const {
    string msg = this->left + "-->";
    for(string str: this->right[0])
    {
        msg += str;
        msg += " ";
    }
    for(auto it = right.begin()+1; it != right.end(); it++)
    {
        msg += "|";
        for(auto it1 = it->begin(); it1 != it->end(); it1++)
        {
            msg += *it1;
            msg += " ";
        }
    }
    return msg;
}

void production::insert(const vector<string> &nodes) {
    right.push_back(nodes);
}

bool production::includeEpsilon() {
    for(size_t i = 0; i < right.size(); i++)
    {
        if(right[i].size() == 1 && right[i][0] == "#")
            return true;
    }
    return false;
}