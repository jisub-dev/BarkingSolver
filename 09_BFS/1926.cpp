#include <bits/stdc++.h>
using namespace std;

int n, m;
int adj [502][502];
int vis [502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }

    int broad = 0;
    queue<pair<int, int>> q;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(adj[i][j] == 1 && vis[i][j] == 0) {
                cnt++;
                vis[i][j] = 1;
                q.push({i, j});
                int area = 1;
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || adj[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        area++;
                        q.push({nx, ny});
                    }
                }   
                broad = max(broad, area);
            }
        }
    }
    cout << cnt << "\n" << broad;

    return 0;
}
