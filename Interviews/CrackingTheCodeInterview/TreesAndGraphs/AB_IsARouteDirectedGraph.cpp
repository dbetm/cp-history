#include <bits/stdc++.h>

using namespace std;
/*
Given a directed graph, design an algorithm to find out whether there is a
route between two nodes.
*/
#define watch(x) cout << (#x) << " is " << x << endl;

bool isARoute(vector<vector<bool>> &directedGraph, int &src, int &dest);

int main() {
    int numNodes, edges, src, dest, queries;
    cin >> numNodes;
    vector<vector<bool>> directedGraph(numNodes, vector<bool>(numNodes, false));

    cin >> edges;
    for (int i = 0; i < edges; ++i) {
        cin >> src >> dest;
        directedGraph[src-1][dest-1] = true;
    }

    cin >> queries;
    for (int i = 0; i < queries; ++i) {
        cin >> src >> dest;
        cout << isARoute(directedGraph, src, dest) << endl;
    }

    return 0;
}

bool isARoute(vector<vector<bool>> &directedGraph, int &src, int &dest) {
    if(src == dest) return true;

    bool ans = false;
    int n = directedGraph.size();
    vector<bool> visited(n, false);
    stack<int> toVisit;
    toVisit.push(src-1);
    // DFS
    while(!toVisit.empty()) {
        int currentNode = toVisit.top();
        visited[currentNode] = true;
        toVisit.pop();

        for (int i = 0; i < n; ++i) {
            if(!visited[i] and directedGraph[currentNode][i]) {
                toVisit.push(i);
                if((dest-1) == i) {
                    ans = true;
                    while(!toVisit.empty()) {
                        toVisit.pop();
                    }
                    break;
                }
            }
        }
    }

    return ans;
}
