#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};

ostream& operator<<(ostream& os, const Meeting& meeting)
{
    return os << "{ startTime: " << to_string(meeting.getStartTime())
              << ", endTime: " << to_string(meeting.getEndTime()) << " }";
}


bool isOverlap(int start1, int end1, int start2, int end2) {
    bool ans = false;

    if(start1 >= start2 || end1 >= end2) {
        ans = true;
    }
    else if(end1 >= start2 || end1 >= start2) {
        ans = true;
    }

    return ans;
}

struct less_than_key {
    inline bool operator() (const Meeting& m1, const Meeting& m2) {
        return (m1.getStartTime() < m2.getStartTime());
    }
};

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
    vector<Meeting> ms(meetings.begin(), meetings.end());
    // merge meeting ranges
    sort(ms.begin(), ms.end(), less_than_key());

    int n = ms.size();
    vector<Meeting> condensed;
    int lowerBound, upperBound;

    for(int i = 0; i < n; i++) {
        lowerBound = ms[i].getStartTime();
        upperBound = ms[i].getEndTime();

        int start1 = ms[i].getStartTime();
        int end1 = ms[i].getEndTime();

        while((i + 1) < n) {
            end1 = upperBound;
            int start2 = ms[i+1].getStartTime();
            int end2 = ms[i+1].getEndTime();

            if(isOverlap(start1, end1, start2, end2)) {
                upperBound = max(upperBound, max(end1, end2));
            }
            else {
                upperBound = max(upperBound, end1);
                break;
            }
            i++;
        }

        condensed.push_back(Meeting(lowerBound, upperBound));
    }

    return condensed;
}

// tests

const lest::test tests[] = {
    {CASE("meetings overlap") {
        const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(2, 4)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 4)};
        EXPECT(actual == expected);
    }},

    {CASE("meetings touch") {
        const auto meetings = vector<Meeting> {Meeting(5, 6), Meeting(6, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(5, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("meeting contains other meeting") {
        const auto meetings = vector<Meeting> {Meeting(1, 8), Meeting(2, 5)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("meetings stay separate") {
        const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("multiple merged meetings") {
        const auto meetings = vector<Meeting> {Meeting(1, 4), Meeting(2, 5), Meeting(5, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("meetings not sorted") {
        const auto meetings = vector<Meeting> {Meeting(5, 8), Meeting(1, 4), Meeting(6, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 4), Meeting(5, 8)};
        EXPECT(actual == expected);
    }},

    {CASE("one long meeting contains smaller meetings") {
        const auto meetings = vector<Meeting> {Meeting(1, 10), Meeting(2, 5), Meeting(6, 8),
            Meeting(9, 10), Meeting(10, 12)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 12)};
        EXPECT(actual == expected);
    }},

    {CASE("sample input") {
        const auto meetings = vector<Meeting> {Meeting(0, 1), Meeting(3, 5), Meeting(4, 8),
            Meeting(10, 12), Meeting(9, 10)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(0, 1), Meeting(3, 8), Meeting(9, 12)};
        EXPECT(actual == expected);
    }},
};

int main(int argc, char** argv)
{
    // return lest::run(tests, argc, argv);
    return 0;
}
