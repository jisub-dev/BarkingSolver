#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v (n, vector<int>(n, -1));
    int min = 0, max = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> v[y][x];
            if (v[y][x] < min) {
                min = v[y][x];
            }
            if (v[y][x] > max) {
                max = v[y][x];
            }
        }
    }
    int area = 0;

    for (int hi = min; hi <= max; hi++) {
        queue<pair<int, int>> q;
        vector<vector<int>> vis (n, vector<int>(n, 0));
        int curArea = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                // 현재 수심보다 높으면 탐색 시작
                if (v[y][x] > hi && vis[y][x] == 0) {
                    curArea++;
                    q.push({y, x});
                    vis[y][x] = 1;
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int yy = cur.first + dy[i];
                            int xx = cur.second + dx[i];
                            if (yy > -1 && yy < n && xx > -1 && xx < n && v[yy][xx] > hi && vis[yy][xx] == 0) {
                                q.push({yy, xx});
                                vis[yy][xx] = 1;
                            }
                        }
                    }
                }
            }
        }
        if (curArea > area) {
            area = curArea;
        }
    }
    cout << area;

    return 0;
}
