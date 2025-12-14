#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    vector<vector<vector<int>>> v (z, vector<vector<int>>(y, vector<int>(x, -1)));  
    
    //1: 익은토마토, 0: 익지 않은 토마토, -1: 토마토 없음
    for (int zz = 0; zz < z; zz++){
        for (int yy = 0; yy < y; yy++) {
            for (int xx = 0; xx < x; xx++) {
                cin >> v[zz][yy][xx];
            }
        }
    }

    // 기본 BFS에 탐색 기준 영역의 z 축 위, 아래의 해당 x, y 좌표만 추가하면 된다.
    queue<tuple<int, int, int>> q;
    for (int zz = 0; zz < z; zz++){
        for (int yy = 0; yy < y; yy++) {
            for (int xx = 0; xx < x; xx++) {
                // 처음에 한번 익은 토마토들만 넣기
                if (v[zz][yy][xx] == 1 ) {
                    q.push({zz, yy, xx});
                }
            }
        }
    }
    
    int cnt = 0; 
    
    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i = 0; i < 6; i++) {
        int zzz = get<0>(cur) + dz[i];
        int yyy = get<1>(cur) + dy[i];
        int xxx = get<2>(cur) + dx[i];
            if (zzz > -1 && zzz < z && yyy > -1 && yyy < y && xxx > -1 && xxx < x && v[zzz][yyy][xxx] == 0) { // 안익은 토마토만 push
                q.push({zzz, yyy, xxx});
                // 이전 영역의 방문 값 + 1 해서 몇일차에 익은건지 표시
                v[zzz][yyy][xxx] = v[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }
    }

    for(auto zz : v) {
        for(auto yy : zz) {
            for (auto xx : yy) {
                if(cnt < xx ) {
                    cnt = xx;
                }
                if (xx == 0){
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    cout << cnt - 1 ;

    return 0;
}
