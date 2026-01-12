#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> wall_list, vir_list;
int a[10][10], vis[10][10];
int n, m, mx;
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

void DFS(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < n && ny > -1 && nx < m && nx > -1 && vis[ny][nx] == 0 && a[ny][nx] != 1) {
            vis[ny][nx] = 1;
            DFS(ny, nx);
        }
    }
}

int sol() {
    fill(&vis[0][0], &vis[0][0] + 10 * 10, 0);
    for (auto vir : vir_list) {
        vis[vir.first][vir.second] = 1;
        DFS(vir.first, vir.second);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0 && a[i][j] != 1) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                vir_list.push_back({i, j});
            }
            if (a[i][j] == 0) {
                wall_list.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < wall_list.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                a[wall_list[i].first][wall_list[i].second] = 1;
                a[wall_list[j].first][wall_list[j].second] = 1;
                a[wall_list[k].first][wall_list[k].second] = 1;
                mx = max(mx, sol());
                a[wall_list[i].first][wall_list[i].second] = 0;
                a[wall_list[j].first][wall_list[j].second] = 0;
                a[wall_list[k].first][wall_list[k].second] = 0;
            }
        }
    }
    cout << mx << "\n";

    return 0;
}