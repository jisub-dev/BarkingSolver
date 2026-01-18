#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int n, r, l, a[104][104], vis[104][104], sum, avg, day, temp[104][104];
vector<pair<int, int>> v;

void DFS(int y, int x) {
    vis[y][x] = 1; 
    sum += a[y][x];
    v.push_back({y, x});
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < n && ny > -1 && nx < n && nx > -1 && vis[ny][nx] == 0){
            int gap = abs(a[ny][nx] - a[y][x]);
            if (gap >= l && gap <= r) {
                DFS(ny, nx);
            }
        } 
    }
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int flag = 1;
    while (true) {
        flag = 0;
        fill(&vis[0][0], &vis[0][0] + 104 * 104, 0);
        fill(&temp[0][0], &temp[0][0] + 104 * 104, -2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    sum = 0;
                    v.clear();
                    DFS(i, j);
                    if (v.size() == 1) continue;
                    flag = 1;
                    for (auto k : v) {
                        temp[k.first][k.second] = sum / v.size();
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] > -1) a[i][j] = temp[i][j];
            }
        }
        if (flag) day++;
        else break;
    }
    cout << day << "\n";

    return 0;
}