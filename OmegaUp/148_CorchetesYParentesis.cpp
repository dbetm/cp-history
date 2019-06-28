#include <iostream>
// https://omegaup.com/arena/problem/Corchetes-y-parentesis#problems
using namespace std;

int main(int argc, char const *argv[]) {
    char c;
    int parentesis = 0, llaves = 0;
    bool flag = false;
    while(cin >> c) {
        if(c == '(') parentesis++;
        else if(c == ')') {
            if(parentesis == 0) flag = true;
            parentesis--;
        }
        else if(c == '{') llaves++;
        else if(c == '}') {
            if(llaves == 0) flag = true;
            llaves--;
        }
    }

    if(flag || parentesis != 0 || llaves != 0) printf("NO\n");
    else printf("SI\n");
    return 0;
}
