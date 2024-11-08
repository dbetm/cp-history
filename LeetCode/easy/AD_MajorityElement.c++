#include <bits/stdc++.h>
// https://leetcode.com/problems/majority-element/
// Tag(s): Implementation, math
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
    int majorityElement(vector<int>& nums) {
        int cand = nums[0];
        int cont = 1, n = nums.size();

        for (int i = 1; i < n; i++) {
            if(nums[i] == cand) cont++;
            else {
                cont--;

                if(cont == 0) {
                    cand = nums[i];
                    cont = 1;
                }
            }
        }

        return cand;
    }
};

int main() {
    fastIO
    Solution sol;
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) cin >> numbers[i];

    cout << sol.majorityElement(numbers) << endl;

	return 0;
}
