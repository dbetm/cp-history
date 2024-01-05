#include <iostream>

using namespace std;

int main() {
    string *sp = new string;
    *sp = "hello";

    cout << sp << endl;
    cout << *sp << endl;

    string word = "we are humans";
    cout << word.substr(7) << endl;
    cout << word.substr(7, 2) << endl;

    cout << word.find("human") << endl;

    return 0;
}
