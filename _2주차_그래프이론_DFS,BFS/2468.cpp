#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1}; 
int n, cnt, high, ans;
int adj[104][104];
int vis[104][104];

void DFS(int y, int x, int h) {
    vis[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < n && ny > -1 && nx < n && nx > -1 && !vis[ny][nx] && adj[ny][nx] > h) {
            DFS(ny, nx, h);
        }
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (high < adj[i][j]) high = adj[i][j];
        }
    }
    for (int h = 0; h < high; h++){
        fill(&vis[0][0], &vis[0][0] + 104 * 104, 0);
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] > h && !vis[i][j]) {
                    cnt++;
                    DFS(i, j, h);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}