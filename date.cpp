#include "date.h"

#include <iomanip>

Date::Date(const int year, const int month, const int day) :
        year_(year), month_(month), day_(day) {}

int Date::GetYear() const {
    return year_;
}

int Date::GetMonth() const {
    return month_;
}

int Date::GetDay() const {
    return day_;
}

Date ParseDate(istream &is) {
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;

    is >> ws;

    return Date(year, month, day);
}

bool operator<(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

bool operator<=(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() <= rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() <= rhs.GetMonth();
    } else {
        return lhs.GetDay() <= rhs.GetDay();
    }
}

bool operator==(const Date &lhs, const Date &rhs) {
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

bool operator!=(const Date &lhs, const Date &rhs) {
    return lhs.GetYear() != rhs.GetYear() || lhs.GetMonth() != rhs.GetMonth() || lhs.GetDay() != rhs.GetDay();
}

bool operator>(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() > rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() > rhs.GetMonth();
    } else {
        return lhs.GetDay() > rhs.GetDay();
    }
}

bool operator>=(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() >= rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() >= rhs.GetMonth();
    } else {
        return lhs.GetDay() >= rhs.GetDay();
    }
}

ostream &operator<<(ostream &stream, const Date &date) {
    stream << setw(4) << setfill('0') << date.GetYear() << "-";
    stream << setw(2) << setfill('0') << date.GetMonth() << "-";
    stream << setw(2) << setfill('0') << date.GetDay();

    return stream;
}