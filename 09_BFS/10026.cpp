#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, -1, 0, 1};

int n;

void bfs(vector<vector<char>> v) {
    vector<vector<int>> vis (n, vector<int>(n, 0));
    queue<pair<int,int>> q;
    int cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if(v[y][x] == 'R' || v[y][x] == 'G' || v[y][x] == 'B') {
                if(vis[y][x] == 0) {
                    cnt++;
                    q.push({y, x});
                    vis[y][x] = 1;
                    while(!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++){
                            int yy = cur.first + dy[i];
                            int xx = cur.second + dx[i];
                            if (yy > -1 && yy < n && xx > -1 && xx < n && v[cur.first][cur.second] == v[yy][xx] && vis[yy][xx] == 0 ) {
                                q.push({yy, xx});
                                vis[yy][xx] = 1;
                            }
                        }
                    }
                }
                
            }
        }
    }
    cout << cnt << " ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            char ch;
            cin >> ch;
            v[y][x] = ch;
        }
    }

    bfs(v);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (v[y][x] == 'G')
                v[y][x] = 'R';
        }
    }
    bfs(v);


    return 0;
}
