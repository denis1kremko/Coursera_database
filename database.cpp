#include "database.h"

#include <algorithm>
#include <stdexcept>

void Database::Add(const Date &date, const string &event) {
    // Если такого события еще не было
    if (events_set[date].count(event) == 0) {
        events_set[date].insert(event);
        events_vec[date].push_back(event);
    }
}

void Database::Print(ostream &stream) const {
    for (const auto &pair : events_vec) {
        for (const string &event : pair.second) {
            stream << pair.first << ' ' << event << "\n";
        }
    }
}

int Database::RemoveIf(const function<bool(Date, string)> &comp) {
    vector<Date> empty_dates;

    int removed = 0;
    for (auto &p : events_vec) {
        auto edge = stable_partition(p.second.begin(), p.second.end(), [p, comp](const string &event) {
            return !comp(p.first, event);
        });

        for (auto iter = edge; iter != p.second.end(); ++iter) {
            events_set[p.first].erase(*iter);
        }

        removed += p.second.end() - edge;
        p.second.erase(edge, p.second.end());

        if (p.second.empty()) {
            empty_dates.push_back(p.first);
        }
    }

    for (const Date &date : empty_dates) {
        events_vec.erase(date);
        events_set.erase(date);
    }

    return removed;
}

vector<pair<Date, string>> Database::FindIf(const function<bool(Date, string)> &comp) const {
    vector<pair<Date, string>> answer;

    for (auto &p : events_vec) {
        for (auto iter = p.second.begin(); iter != p.second.end(); ++iter) {
            if (comp(p.first, *iter)) {
                answer.push_back(make_pair(p.first, *iter));
            }
        }
    }

    return answer;
}

pair<Date, string> Database::Last(const Date &date) const {
    auto iter = events_vec.upper_bound(date);
    if (iter == events_vec.begin()) {
        throw invalid_argument("invalid_argument");
    } else {
        return make_pair(prev(iter)->first, prev(iter)->second.back());
    }
}