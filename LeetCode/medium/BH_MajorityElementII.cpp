#include <bits/stdc++.h>
// https://leetcode.com/problems/majority-element-ii/
// Tag(s): Implementation, math
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    if(n == 0) return ans;
    else if(n == 1) {
        ans.push_back(nums[0]);
        return ans;
    }
    else if(n == 2) {
        ans.push_back(nums[0]);
        if(nums[1] != nums[0]) ans.push_back(nums[1]);
        return ans;
    }

    /* [10%, 20%, 30% | 40%, 50%, 60% | 70%, 80%, 90%] we could have max 2 majority
    elements, because x>(n/3), y>(n/3), n/3 < (x + y)
    The idea is building triples with different elements, if we have leftovers,
    then they are candidates for be majority elements, because they are probably
    more than 1/3 of the total number of elements in the array. How to create
    triples? We can use two counters for two current different elements, so
    we can count the repeated elements until find a third different, when
    we can generate a triple we decrease both counters because we are using
    them. Afer that, we are gonna check if the remaining current different elements
    are appearing more than n/3 times. ALGORITHM: Boyer-Moore Majority Vote.
    */
    int contA = 1, contB = 0, a = nums[0], b;

    for (int i = 1; i < n; ++i) {
        if(nums[i] == a) ++contA;
        else if(contB == 0) {
            b = nums[i];
            contB = 1;
        }
        else if(nums[i] == b) ++contB;
        else if(contA == 0) {
            a = nums[i];
            contA = 1;
        }
        else {
            --contA;
            --contB;
        }
    }

    int checkerContA = 0, checkerContB = 0;
    for(const auto & element : nums) {
        if(contA > 0 and a == element) ++checkerContA;
        else if(contB > 0 and b == element) ++checkerContB;
    }

    int threshold = n / 3;
    if(checkerContA > threshold) ans.push_back(a);
    if(checkerContB > threshold) ans.push_back(b);

    return ans;
}


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; ++i) cin >> nums[i];

    vector<int> ans = majorityElement(nums);

    for(auto num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
