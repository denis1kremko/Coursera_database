#pragma once

#include "date.h"
#include "node.h"

#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <utility>
#include <set>

using namespace std;

class Database {
public:
    void Add(const Date &date, const string &event);

    void Print(ostream &stream) const;

    int RemoveIf(const function<bool(Date, string)> &comp);

    vector<pair<Date, string>> FindIf(const function<bool(Date, string)> &comp) const;

    pair<Date, string> Last(const Date &date) const;

private:
    map<Date, vector<string>> events_vec;
    map<Date, set<string>> events_set;
};