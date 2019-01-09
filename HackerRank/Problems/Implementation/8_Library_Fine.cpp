#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/library-fine/problem
using namespace std;

int main(int argc, char* argv[]) {
    int day, month, year, _day, _month, _year;
    int fine;

    // the respective day, month and year on which the book was returned.
    cin >> day >> month >> year;
    // the respective day, month and year on which the book was due to be returned.
    cin >> _day >> _month >> _year;

    // case 1: if the book was returned on or before the returned date
    if((day <= _day && month == _month && year == _year) ||
      (month < _month && year == _year) || year < _year) {
        fine = 0;
    }
    // case 2: when the book was returned days late but the same month and year
    else if(day > _day && month == _month && year == _year) {
        fine = (day - _day) * 15;
    }
    // case 3: when the book was returned other month but the same year
    else if(month > _month && year == _year) {
        fine = (month - _month) * 500;
    }
    // case 4: when the book was returned other year
    else {
        fine = 10000;
    }

    cout << fine << endl;

    return 0;
}
