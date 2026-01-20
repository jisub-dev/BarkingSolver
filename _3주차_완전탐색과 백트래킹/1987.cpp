#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int r, c, alph[30], res;
string str;
char a[24][24];

void DFS(int y, int x, int cnt){
    res = max(res, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < r && ny > -1 && nx < c && nx > -1) {
            int idx = a[ny][nx] - 'A';
            if(alph[idx] == 0) {
                alph[idx] = 1;
                DFS(ny, nx, cnt + 1);
                alph[idx] = 0;
            }
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++){
            a[i][j] = str[j];
        }
    }
    int idx = a[0][0] - 'A';
    alph[idx] = 1;
    DFS(0, 0, 1);
    cout << res << "\n";


    return 0;
}