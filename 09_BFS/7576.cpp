#include <bits/stdc++.h>
using namespace std;

int adj[1002][1002];
int vis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    queue<pair<int, int>> q;
    int ans = -1;
    int err = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
            if (adj[i][j] == -1)
            {
                vis[i][j] = 1;
            }
        }
    }
    q.push({-1, -1});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || adj[nx][ny] != 0)
                continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
        if (!q.empty() && q.front().first == -1)
        {
            q.pop();
            q.push({-1, -1});
            ans++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0)
            {
                err = 1;
                break;
            }
        }
    }

    if (err)
    {
        cout << -1;
    }
    else
        cout << ans;

    return 0;
}
