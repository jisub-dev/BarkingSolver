#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v (n, (vector<int> (n, -1)));
    vector<vector<int>> vis (n, (vector<int> (n, 0)));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            char ch;
            cin >> ch;
            v[y][x] = ch - '0';
        }
    }
    vector<int> areas;
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (v[y][x] == 1 && vis[y][x] == 0) {
                cnt++;
                q.push({y, x});
                vis[y][x] = 1;
                int area = 1;
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int yy = cur.first + dy[i];
                        int xx = cur.second + dx[i];
                        if (yy > -1 && yy < n && xx > -1 && xx < n && v[yy][xx] == 1 && vis[yy][xx] == 0) {
                            q.push({yy, xx});
                            vis[yy][xx] = 1;
                            area++;
                        }
                    
                    }
                }
                areas.push_back(area);
                
            }
        }
    }
    sort(areas.begin(), areas.end());
    
    cout << cnt << "\n";
    for(int a : areas) {
        cout << a << "\n";
    }


    return 0;
}
