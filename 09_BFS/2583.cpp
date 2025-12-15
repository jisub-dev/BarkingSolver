#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int mx, my, sq;
    cin >> mx >> my >> sq;
    vector<vector<int>> v (my, (vector<int> (mx, 0)));
    vector<vector<int>> vis (my, (vector<int> (mx, 0)));
    
    for (int i = 0; i < sq; i++) {
        int sy, sx;
        int ey, ex;
        cin >> sy >> sx;
        cin >> ey >> ex;
        for (int n = sy; n < ey; n++) {
            for (int m = sx; m < ex; m++) {
                v[n][m] = 1;
            }
        }
    }
    vector<int> areaList;
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int y = 0; y < my; y++) {
        for (int x = 0; x < mx; x++) {
            if (v[y][x] == 0 && vis[y][x] == 0) {
                int area = 1;
                cnt++;
                q.push({y, x});
                vis[y][x] = 1;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int yy = cur.first + dy[i];
                        int xx = cur.second + dx[i];
                        if (yy > -1 && yy < my && xx > -1 && xx < mx && v[yy][xx] == 0 && vis[yy][xx] == 0) {
                            area++;
                            q.push({yy, xx});
                            vis[yy][xx] = 1;
                        }
                    }
                }
                areaList.push_back(area);
            }
        }
    }
    cout << cnt << "\n";
    
    sort(areaList.begin(), areaList.end());
    for(int a : areaList) {
        cout <<a << " ";
    }

    return 0;
}
