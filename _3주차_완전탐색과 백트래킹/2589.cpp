#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, mx;
char a[54][54];
string str;
int vis[54][54];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
            cin >> str;
            for (int k = 0; k < str.length(); k++){
                a[i][k] = str[k];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'L') {
                queue<pair<int, int>> q;
                fill(&vis[0][0], &vis[0][0] + 54 * 54, -1);
                q.push({i, j});
                vis[i][j] = 0;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int ny = cur.first + dy[k];
                        int nx = cur.second + dx[k];
                        if (ny < n && ny > -1 && nx < m && nx > -1 && a[ny][nx] == 'L' && vis[ny][nx] == -1) {
                            vis[ny][nx] = vis[cur.first][cur.second] + 1;
                            mx = max(mx, vis[ny][nx]);
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
    }
    cout << mx << "\n";

    return 0;
}