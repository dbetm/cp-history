#include <bits/stdc++.h>
// https://leetcode.com/problems/valid-parentheses/
// Tag(s): Implementation, data structures
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

class Solution {
public:
    bool isValid(string expression) {
        int n = expression.size();
        stack<char> myStack;

        for (int i = 0; i < n; i++) {

            if(expression[i] == '(' or expression[i] == '{' or expression[i] == '[') {
                myStack.push(expression[i]);
            }
            else {
                if(myStack.empty()) return false;
                else if (expression[i] == ')') {
                    if('(' == myStack.top()) myStack.pop();
                    else return false;
                }
                else if (expression[i] == '}') {
                    if('{' == myStack.top()) myStack.pop();
                    else return false;
                }
                else {
                    if('[' == myStack.top()) myStack.pop();
                    else return false;
                }
            }
        }

        return myStack.empty();
    }
};

int main() {
    fastIO
    string expression;
    Solution sol;

    cin >> expression;

    cout << sol.isValid(expression) << endl;

	return 0;
}
