#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
char a[1504][1504];
int r, c, day, vis[1504][1504], bak_vis[1504][1504];
vector<pair<int, int>> bak;
stack<pair<int, int>> s;
queue<pair<int, int>> q, nq, sq, nsq;

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'L'){
                bak.push_back({i, j});
            }
            if(a[i][j] == '.' || a[i][j] == 'L') {
                q.push({i, j});
            }
        }
    }

    while (true) {
        sq.push({bak[0].first, bak[0].second});
        while(!sq.empty()) {
            auto fro = sq.front();
            sq.pop();
            bak_vis[fro.first][fro.second] = 1;
            if (fro.first == bak[1].first && fro.second == bak[1].second) {
                cout << day << "\n";
                exit(0);
            }
            for (int i = 0; i < 4; i++) {
                    int ny = fro.first + dy[i];
                    int nx = fro.second + dx[i];
                    if (ny < r && ny > -1 && nx < c && nx > -1 && !bak_vis[ny][nx]) {
                        if (a[ny][nx] == 'X'){    
                            bak_vis[ny][nx] = 1;
                            nsq.push({ny, nx});
                        }
                        else {
                            bak_vis[ny][nx] = 1;
                            sq.push({ny, nx});
                        }
                    }
            }
        }
        sq = nsq;
        while (!nsq.empty()) {
            nsq.pop();
        }
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            auto fro = q.front();
            q.pop();
            vis[fro.first][fro.second] = 1;
            for (int i = 0; i < 4; i++) {
                int ny = fro.first + dy[i];
                int nx = fro.second + dx[i];
                if (ny < r && ny > -1 && nx < c && nx > -1 && !vis[ny][nx]) {
                    if (a[ny][nx] == 'X') {
                        s.push({ny, nx});
                        nq.push({ny, nx});
                        vis[ny][nx] = 1;
                    }
                    else {
                        vis[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
        q = nq;
        while (!nq.empty()) {
            nq.pop();
        }
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            a[cur.first][cur.second] = '.';
        }
        day++;
    }

    return 0;
}