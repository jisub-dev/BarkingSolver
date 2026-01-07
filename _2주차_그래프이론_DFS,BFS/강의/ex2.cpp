#include <bits/stdc++.h>
using namespace std;
const int n = 6;
vector<int> adj[n];
int vis[n];

void DFS(int u) {
    vis[u] = 1;
    cout << u << "\n";
    for (auto v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    DFS(1);
    return 0;
}