#include <bits/stdc++.h>
using namespace std;

int pre_cnt, cur_cnt, tim, n, m;
int a[104][104], vis[104][104];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void DFS(int y, int x) {
    vis[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < n && ny > -1 && nx < m && nx > -1) {
            if (a[ny][nx] == 1 && vis[ny][nx] != 1 && a[y][x] == 0) {
                vis[ny][nx] = 2;
            }
            if (a[ny][nx] == 0 && vis[ny][nx] == 0) {
                DFS(ny, nx);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    cur_cnt++;
                }
            }
        }
        if (!cur_cnt) {
            cout << tim << "\n" << pre_cnt << "\n";
            return 0;
        }
        else {
            pre_cnt = cur_cnt;
        }
        tim++;
        cur_cnt = 0;
        fill(&vis[0][0], &vis[0][0] + 104 * 104, 0);
        DFS(0, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 2) {
                    a[i][j] = 0;
                }
            }
        }
        
    }

    return 0;
}