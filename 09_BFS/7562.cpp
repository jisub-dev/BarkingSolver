#include <bits/stdc++.h>
using namespace std;

int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int r = 0; r < t; r++) {
        int n; 
        cin >> n;
        vector<vector<int>> v (n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        int y, x;
        cin >> y >> x;
        int ty, tx;
        cin >> ty >> tx;
        if (y == ty && x == tx) cout << "0"<< "\n";
        q.push({y, x});
        v[y][x] = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                int yy = cur.first + dy[i];
                int xx = cur.second + dx[i];
                if (yy > -1 && yy < n && xx > -1 && xx < n && v[yy][xx] == -1) {
                    if (yy == ty && xx == tx) {
                        cout << v[cur.first][cur.second] + 1 << "\n";
                        while(!q.empty()) q.pop();
                        break;
                    }
                    q.push({yy, xx});
                    v[yy][xx] = v[cur.first][cur.second] + 1;
                }
            }
        }
    }

    return 0;
}
