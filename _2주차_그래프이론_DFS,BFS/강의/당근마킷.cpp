#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
queue<pair<int, int>> q;
int maxy, maxx, dis, sy, sx, fy, fx, adj[max_n][max_n], vis[max_n][max_n];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {

    cin >> maxy >> maxx >> sy >> sx >> fy >> fx;
    for (int i = 0; i < maxy; i++){
        for (int j = 0; j < maxx; j++){
            cin >> adj[i][j];
        }
    }

    q.push({sy, sx});
    vis[sy][sx] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < maxy && ny > -1 && nx < maxx && nx > -1 && !vis[ny][nx] && adj[ny][nx]) {
                q.push({ny, nx});
                vis[ny][nx] = vis[cur.first][cur.second] + 1;
                if (vis[ny][nx] > dis) dis = vis[ny][nx];
                if (ny == fy && nx == fx) {
                    cout << dis << "\n";
                    return 0;
                }
            }
        }
    }


    return 0;
}