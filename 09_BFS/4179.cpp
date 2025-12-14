#include <bits/stdc++.h>
using namespace std;

char adj[1002][1002];
int vis_jh[1002][1002];
int vis_fire[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;
    int r, c;
    string str;
    cin >> r >> c;
    pair<int, int> jh;

    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            adj[i][j] = str[j];
            if (str[j] == 'J') jh = make_pair(i, j);
            if (str[j] == 'F') {
                q.push({i, j});
                vis_fire[i][j] = 1;
            }
        }
    }    

    if (jh.first == 0 || jh.first == r - 1 || jh.second == 0 || jh.second == c - 1) {
        cout << 1 << "\n";
        return 0;
    }

    while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (vis_fire[nx][ny] != 0 || adj[nx][ny] == '#') continue;

                vis_fire[nx][ny] = vis_fire[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }

    while (!q.empty()) q.pop();

    q.push({jh.first, jh.second});
    vis_jh[jh.first][jh.second] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << vis_jh[cur.first][cur.second] << "\n";
                return 0;
            }
            if (vis_jh[nx][ny] != 0) continue;
            if (adj[nx][ny] == '#') continue;
            if (vis_fire[nx][ny] != 0 && vis_fire[nx][ny] <= vis_jh[cur.first][cur.second] + 1) continue;

            vis_jh[nx][ny] = vis_jh[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";
    
    return 0;
}
