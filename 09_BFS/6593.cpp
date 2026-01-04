#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l, r, c;
    cin >> l >> r >> c;

    while (l != 0 && r != 0 && c != 0) {
        int flag = 0;
        vector<vector<vector<char>>> v (l, vector<vector<char>> (r, vector<char> (c)));
        vector<vector<vector<int>>> dis (l, vector<vector<int>> (r, vector<int> (c, -1)));
        int sy, sx, sz;
        int ez, ey, ex;
        for (int ll = 0; ll < l; ll++) {
            for (int rr = 0; rr < r; rr++) {
                for (int cc = 0; cc < c; cc++) {
                    cin >> v[ll][rr][cc];
                    if (v[ll][rr][cc] == 'S') {
                        sz = ll;
                        sy = rr;
                        sx = cc;
                    }
                    if (v[ll][rr][cc] == 'E') {
                        ez = ll;
                        ey = rr;
                        ex = cc;
                    }
                }
            }
        }
        queue<tuple<int, int, int>> q;
        q.push(make_tuple(sz, sy, sx));
        dis[sz][sy][sx] = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 6; i++) {
                int zz = get<0>(cur) + dz[i];
                int yy = get<1>(cur) + dy[i];
                int xx = get<2>(cur) + dx[i];
                if (zz > -1 && zz < l && yy > -1 && yy < r && xx > -1 && xx < c && (v[zz][yy][xx] == '.' || v[zz][yy][xx] == 'E') && dis[zz][yy][xx] == -1) {
                    if (zz == ez && yy == ey && xx == ex) {
                        cout << "Escaped in " << dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1 << " minute(s).\n";
                        flag = 1;
                        break;
                    }
                    q.push(make_tuple(zz, yy, xx));
                    dis[zz][yy][xx] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                }
            }
            if (flag) break;
        }
        if (!flag) cout << "Trapped!\n";
        cin >> l >> r >> c;
    }
    

    return 0;
}
