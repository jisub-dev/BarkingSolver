#include <bits/stdc++.h>
using namespace std;

int n, k;
bool vis[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(vis, vis + 100001, false);

    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n, 0});
    vis[n] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();

        if (x == k) {
            cout << t;
            break;
        }

        
        int nx = x + 1;
        if (nx >= 0 && nx <= 100000 && !vis[nx]) { 
            q.push({nx, t + 1});
            vis[nx] = true;
        }
        
        nx = x - 1;
        if (nx >= 0 && nx <= 100000 && !vis[nx]) { 
            q.push({nx, t + 1});
            vis[nx] = true;
        }        
        
        nx = 2 * x;
        if (nx >= 0 && nx <= 100000 && !vis[nx]) { 
            q.push({nx, t + 1});
            vis[nx] = true;
        }
    }


    return 0;
}
