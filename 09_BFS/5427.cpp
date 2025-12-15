#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tk;
    cin >> tk;
    for (int r = 0; r < tk; r++) {
        int flag = 0;
        int ny, nx;
        cin >> nx >> ny;
        vector<vector<char>> v (ny, vector<char> (nx));
        queue<tuple<int, int, char>> q;
        tuple<int, int, char> tu;
        vector<vector<int>> dist (ny, vector<int> (nx, -1));
        for (int i = 0; i < ny; i++) {
            for (int j = 0; j < nx; j++) {
                cin >> v[i][j];
                if (v[i][j] == '*') {
                    q.push(make_tuple(i, j, v[i][j]));
                }
                if (v[i][j] == '@') {
                    tu = make_tuple(i, j, v[i][j]);
                    dist[i][j] = 0;
                }
            }
        }
        // 수근이 좌표는 나중에 넣음
        q.push(tu);

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int yy = get<0>(cur) + dy[i];
                int xx = get<1>(cur) + dx[i];
                char id = get<2>(cur); 
                if (yy > -1 && yy < ny && xx > -1 && xx < nx && v[yy][xx] != '#') {
                    // 불일때
                    if (id == '*' && (v[yy][xx] == '.' || v[yy][xx] == '@')) {
                        v[yy][xx] = '*';
                        q.push(make_tuple(yy, xx, '*'));
                    }
                    else if (id == '@' && v[yy][xx] == '.' && dist[yy][xx] == -1) {
                        v[yy][xx] = '@';
                        q.push(make_tuple(yy, xx, '@'));
                        dist[yy][xx] = dist[get<0>(cur)][get<1>(cur)] + 1;
                    }
                }
                // 나가면 탈출
                else if (id == '@' &&(yy < 0 || yy > ny - 1 || xx < 0 || xx > nx -1)){
                    cout << dist[get<0>(cur)][get<1>(cur)] + 1 << "\n";
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) cout << "IMPOSSIBLE\n";

    }

    return 0;
}
