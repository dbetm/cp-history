#include <bits/stdc++.h>

using namespace std;
/*
Given a directed graph, design an algorithm to find out whether there is a 
route between two nodes.
*/
#define watch(x) cout << (#x) << " is " << x << endl;

bool isThereARoute(vector<vector<int>> &graph, int &src, int &dest);
void dfs(vector<vector<int>> &graph, int i, bool visited[], bool &ans, int &dest);

int main() {
    int numNodes, edges, src, dest, queries;
    cin >> numNodes;
    vector<vector<int>> graph;

    for (int i = 0; i <= numNodes; i++) {
        graph.push_back({});
    }

    cin >> edges;
    for (int i = 0; i < edges; ++i) {
        cin >> src >> dest;
        graph[src].push_back(dest);
    }

    cin >> queries;
    for (int i = 0; i < queries; ++i) {
        cin >> src >> dest;
        cout << isThereARoute(graph, src, dest) << endl;
    }

    return 0;
}

bool isThereARoute(vector<vector<int>> &graph, int &src, int &dest) {
    int n = graph.size();
    bool ans = false;
    bool visited[n+1] = {false};

    dfs(graph, src, visited, ans, dest);

    return ans;
}

void dfs(vector<vector<int>> &graph, int i, bool visited[], bool &ans, int &dest) {
    int n = graph[i].size();
    if(visited[i] || n == 0) return;

    visited[i] = true;

    for (int x = 0; x < n; ++x) {
        if(graph[i][x] == dest) {
            ans = true;
            break;
        }
        else {
            dfs(graph, graph[i][x], visited, ans, dest);
        }
    }
}
