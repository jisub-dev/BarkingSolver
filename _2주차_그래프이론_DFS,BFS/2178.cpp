#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int my, mx, dis;
int adj[max_n][max_n];
int vis[max_n][max_n];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    cin >> my >> mx;
    for (int i = 0; i < my; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < mx; j++) {
            adj[i][j] = temp[j] - '0';
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < my && ny > -1 && nx < mx && nx > -1 && !vis[ny][nx] && adj[ny][nx]) {
                q.push({ny, nx});
                vis[ny][nx] = vis[cur.first][cur.second] + 1;
                if (vis[ny][nx] > dis) dis = vis[ny][nx];
            }
            if (ny == my - 1 && nx == mx - 1) {
                cout << dis << "\n";
                return 0;
            }

        }
    }

    return 0;
}