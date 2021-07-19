#pragma once

#include "date.h"

#include <string>
#include <memory>

enum Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum LogicalOperation {
    Or,
    And
};

class Node {
public:
    virtual bool Evaluate(const Date &date, const string &event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date &date, const string &event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison &cmp, const Date &date);

    bool Evaluate(const Date &date, const string &event) const override;

private:
    const Date date_;
    const Comparison cmp_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison &cmp, const string &event);

    bool Evaluate(const Date &date, const string &event) const override;

private:
    const string event_;
    const Comparison cmp_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation &op, const shared_ptr<Node> &left, const shared_ptr<Node> &right);

    bool Evaluate(const Date &date, const string &event) const override;

private:
    const shared_ptr<Node> left_;
    const shared_ptr<Node> right_;
    const LogicalOperation op_;
};