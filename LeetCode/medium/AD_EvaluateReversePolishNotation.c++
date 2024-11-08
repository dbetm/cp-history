#include <bits/stdc++.h>
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
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
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            if((tokens[i][0] >= '0' and tokens[i][0] <= '9') or (tokens[i][0] == '-' and tokens[i].size() > 1)) {
                myStack.push(atoi(tokens[i].c_str()));
            }
            else {
                int num2 = myStack.top();
                //watch(num2)
                myStack.pop();
                int num1 = myStack.top();
                myStack.pop();
                //watch(num1)
                if(tokens[i] == "+") myStack.push(num1 + num2);
                if(tokens[i] == "*") myStack.push(num1 * num2);
                if(tokens[i] == "/") myStack.push(num1 / num2);
                if(tokens[i] == "-") myStack.push(num1 - num2);
            }
        }

        return myStack.top();
    }
};

int main() {
    fastIO
    int n;
    cin >> n;
    vector<string> posfixExpression(n);

    for (int i = 0; i < n; i++) cin >> posfixExpression[i];

    Solution sol;
    cout << sol.evalRPN(posfixExpression) << endl;

	return 0;
}
