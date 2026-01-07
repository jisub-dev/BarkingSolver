#include <bits/stdc++.h>
using namespace std;
const int dy[] = {1, 0, -1 ,0};
const int dx[] = {0, 1, 0, -1};

int tc, maxy, maxx, k, y, x;

void DFS(const vector<vector<int>> &adj, vector<vector<int>> &vis, int yyy, int xxx) {
    vis[yyy][xxx] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = yyy + dy[i];
        int nx = xxx + dx[i];
        if (ny < maxy && ny > -1 && nx < maxx && nx > -1 && adj[ny][nx] && !vis[ny][nx]) {
            DFS(adj, vis, ny, nx);
        }
    }
} 

int main() {
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        int cnt = 0;
        cin >> maxy >> maxx >> k;
        vector<vector<int>> adj (maxy, vector<int> (maxx, 0));
        vector<vector<int>> vis (maxy, vector<int> (maxx, 0));
        for (int j = 0; j < k; j++) {
            cin >> y >> x;
            adj[y][x] = 1;
        }
        for (int yy = 0; yy < maxy; yy++) {
            for (int xx = 0; xx < maxx; xx++) {
                if (adj[yy][xx] && !vis[yy][xx]) {
                    cnt++;
                    DFS(adj, vis, yy, xx);
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}