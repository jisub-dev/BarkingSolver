/**
 * 지훈이를 벡터에 넣고
 * 불로 BFS 1칸 (., J 로만)
 * 지훈 BFS 1칸 (. 인곳으로만)
 * 이 순서대로 
 */

#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int r, c, eend;
vector<vector<char>> v;
vector<vector<int>> vis;
string str;
queue<pair<int, int>> ji, fir;

void BFS(int y, int x, char sep) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < r && ny > -1 && nx < c && nx > -1) {
            if (sep == 'F') {
                if (v[ny][nx] == '.' || v[ny][nx] == 'J') {
                    v[ny][nx] = 'F';
                    fir.push({ny, nx});
                }
            }
            if (sep == 'J') {
                if (v[ny][nx] == '.') {
                    v[ny][nx] = 'J';
                    ji.push({ny, nx});
                    vis[ny][nx] = vis[y][x] + 1;
                }
            }
        }
        else {
            if (sep == 'J') {
                cout << vis[y][x] + 1 << "\n"; 
                exit(0);
            }
        }
    }
}

int main() {
    cin >> r >> c;
    v.assign(r, vector<char>(c, '.'));
    vis.assign(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            v[i][j] = str[j];
            if(str[j] == 'J') {
                ji.push({i, j});
            }
            if (str[j] == 'F') {
                fir.push({i, j});
            }
        }
    }
    while (!ji.empty()) {
        eend = fir.size();
        for (int i = 0; i < eend; i++) {
            auto cur = fir.front();
            fir.pop();
            BFS(cur.first, cur.second, 'F');
        }
        eend = ji.size();
        for (int i = 0; i < eend; i++) {
            auto cur = ji.front();
            ji.pop();
            BFS(cur.first, cur.second, 'J');
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}