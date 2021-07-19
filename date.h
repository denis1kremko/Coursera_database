#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class Date {
public:
    Date(int year, int month, int day);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

private:
    const int year_;
    const int month_;
    const int day_;
};

Date ParseDate(istream &is);

bool operator<(const Date &lhs, const Date &rhs);

bool operator<=(const Date &lhs, const Date &rhs);

bool operator==(const Date &lhs, const Date &rhs);

bool operator!=(const Date &lhs, const Date &rhs);

bool operator>(const Date &lhs, const Date &rhs);

bool operator>=(const Date &lhs, const Date &rhs);

ostream &operator<<(ostream &stream, const Date &date);