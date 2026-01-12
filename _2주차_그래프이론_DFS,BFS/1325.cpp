#include <bits/stdc++.h>
using namespace std;

int n, m, mx, st, ed;
vector<vector<int>> v;
vector<int> com;
int vis[10004];

int DFS(int i){
    if(vis[i] == 1) {
        return 0;
    }
    vis[i] = 1;
    int cnt = 1;
    for (auto j : v[i]) {
        cnt += DFS(j);
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    v.resize(n + 1, vector<int>(0, 0));
    for (int i = 0; i < m; i++) {
        cin >> st >> ed;
        v[ed].push_back(st);
    }
    for (int i = 1; i <= n; i++) {
        fill(&vis[0], &vis[0] + n + 1, 0);
        int cnt = DFS(i);
        if (mx < cnt) {
            mx = cnt;
            com.clear();
            com.push_back(i);
        }
        else if (mx == cnt) {
            com.push_back(i);
        }

    }
    for (auto i : com) {
        cout << i << " ";
    }

    return 0; 
}