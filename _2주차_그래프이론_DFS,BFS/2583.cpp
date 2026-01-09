#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int y, x, k, sy, sx, ty, tx, adj[104][104], vis[104][104], res;
queue<pair<int, int>> q;
vector<int> area;

int main(){
    cin >> y >> x >> k;
    for (int i = 0; i < k; i++) {
        cin >> sx >> sy >> tx >> ty;
        for (int j = sy; j < ty; j++) {
            for (int l = sx; l < tx; l++) {
                adj[j][l] = 1;
            }
        }
    }
    for(int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (!adj[i][j] && !vis[i][j]) {
                res++;
                q.push({i, j});
                vis[i][j] = 1;
                int mx = 1;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int ny = cur.first + dy[i];
                        int nx = cur.second + dx[i];
                        if (ny < y && ny > -1 && nx < x && nx > -1 && !vis[ny][nx] && !adj[ny][nx]) {
                            q.push({ny, nx});
                            vis[ny][nx] = 1;
                            mx++;
                        }
                    }
                }
                area.push_back(mx);
            }
        }
    } 
    cout << res << "\n";
    sort(area.begin(), area.end());
    for (int i : area) {
        cout << i << " ";
    }

    return 0;
}

