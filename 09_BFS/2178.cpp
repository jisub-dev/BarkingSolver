#include <bits/stdc++.h>
using namespace std;

int adj[502][502];
int vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string temp;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            adj[i][j] = temp[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    vis[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || adj[nx][ny] != 1) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << vis[n - 1][m - 1];
    return 0;
}
