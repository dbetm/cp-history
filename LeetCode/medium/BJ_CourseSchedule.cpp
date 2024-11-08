#include <bits/stdc++.h>
// https://leetcode.com/problems/course-schedule/
// Tag(s): DFS, topological sort
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if(numCourses == 1) return true;

    vector<vector<int>> list(numCourses);
    vector<int> inDegrees(numCourses, 0);

    for(const auto & pre : prerequisites) {
        list[pre[1]].push_back(pre[0]);
        inDegrees[pre[0]]++;
    }

    queue<int> q;

    for (int i = 0; i < numCourses; ++i) {
        if(inDegrees[i] == 0) q.push(i);
    }

    int permissibleCourses = 0;

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int j = 0; j < list[vertex].size(); ++j) {
            inDegrees[list[vertex][j]]--;

            if(inDegrees[list[vertex][j]] == 0) {
                q.push(list[vertex][j]);
            }
        }
        ++permissibleCourses;
    }

    return permissibleCourses == numCourses;
}

int main() {
    int n, a, b, m;
    cin >> n;

    cin >> m;
    vector<vector<int>> prerequisites(m);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        prerequisites[i].push_back(a);
        prerequisites[i].push_back(b);
    }

    cout << canFinish(n, prerequisites) << endl;

    return 0;
}
