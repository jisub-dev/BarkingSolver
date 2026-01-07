#include <bits/stdc++.h>
using namespace std;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int adj[104][104];
int vis[104][104];
int n, m, cnt;

void DFS(int y, int x) {
    vis[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < n && ny > -1 && nx < m && nx > -1 && !vis[ny][nx] && adj[ny][nx]) {
            DFS(ny, nx);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!vis[i][j] && adj[i][j]) {
                cnt++;
                DFS(i, j);
            }
        }
    }

    cout << cnt;
    return 0;
}