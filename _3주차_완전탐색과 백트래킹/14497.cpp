#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int _y1, y2, x1, x2, n, m, vis[304][304], a[304][304], cnt;
string str;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> _y1 >> x1 >> y2 >> x2;
    _y1--; x1--; y2--; x2--;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if(str[j] == '1') {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 0;
            }
        }
    }
    while (true) {
        q = {};
        cnt++;
        vector<pair<int, int>> temp;
        fill(&vis[0][0], &vis[0][0] + 304 * 304, 0);
        q.push({_y1, x1});
        vis[_y1][x1] = 1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int ny = cur.first + dy[j];
                int nx = cur.second + dx[j];
                if (ny < n && ny > -1 && nx < m && nx > -1 && vis[ny][nx] == 0) {
                    if (ny == y2 && nx == x2) {
                        cout << cnt << "\n";
                        exit(0);
                    }
                    if (a[ny][nx] == 0) {
                        q.push({ny, nx});
                        vis[ny][nx] = 1;
                    } 
                    else if (a[ny][nx] == 1) {
                        temp.push_back({ny, nx});
                    }
                    
                }
                
            }
        }
        for (auto i : temp) {
            a[i.first][i.second] = 0;
        }
    }


    return 0;
}