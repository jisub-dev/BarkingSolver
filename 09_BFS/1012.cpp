#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1 , 0 , -1 , 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int r = 0; r < t; r++) {
        int cnt = 0;
        queue<pair<int,int>> q;
        int y, x; // x: 가로 , y: 세로
        cin >> x >> y;
        vector<vector<int>> v(y, vector<int>(x, 0));
        vector<vector<int>> vis(y, vector<int>(x, 0));

        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int yy;
            int xx;
            cin >> xx >> yy;
            v[yy][xx] = 1;
        }

        for (int yy = 0; yy < y; yy++) {
            for (int xx = 0; xx < x; xx++) {
                if (vis[yy][xx] == 0 && v[yy][xx] == 1) {
                    cnt++;
                    vis[yy][xx] = 1;
                    q.push({yy, xx});

                    while(!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int h = 0; h < 4; h++) {
                            int nx = cur.second + dx[h];
                            int ny = cur.first + dy[h];
                            if (nx > -1 && nx < x && ny > -1 && ny < y && vis[ny][nx] == 0 && v[ny][nx] == 1) {
                                q.push({ny, nx});
                                vis[ny][nx] = 1;
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << "\n";
   
    }

    return 0;
}
