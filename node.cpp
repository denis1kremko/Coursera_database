#include "node.h"

#include <memory>

bool EmptyNode::Evaluate(const Date &date, const string &event) const {
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date) : date_(date), cmp_(cmp) {}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) const {
    if (cmp_ == Comparison::Equal) {
        return date == date_;
    } else if (cmp_ == Comparison::Less) {
        return date < date_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return date <= date_;
    } else if (cmp_ == Comparison::Greater) {
        return date > date_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return date >= date_;
    } else {
        return date != date_;
    }
}

EventComparisonNode::EventComparisonNode(const Comparison &cmp, const string &event) : event_(event), cmp_(cmp) {}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    if (cmp_ == Comparison::Equal) {
        return event == event_;
    } else if (cmp_ == Comparison::Less) {
        return event < event_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return event <= event_;
    } else if (cmp_ == Comparison::Greater) {
        return event > event_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return event >= event_;
    } else {
        return event != event_;
    }
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &op, const shared_ptr<Node> &left,
                                           const shared_ptr<Node> &right) : left_(left), right_(right), op_(op) {}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    if (op_ == LogicalOperation::And) {
        return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    } else {
        return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    }
}