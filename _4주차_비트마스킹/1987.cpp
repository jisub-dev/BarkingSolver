#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
char a[24][24];
string str;
int my, mx, idx, ret;

void dfs(int y, int x, int dept, int mask) {
    ret = max(ret, dept);
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > -1 && ny < my && nx > -1 && nx < mx){
            idx = a[ny][nx] - 'A';
            if(!(mask & (1 << idx))) {
                dfs(ny, nx, dept + 1, mask | (1 << idx));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> my >> mx;
    for(int i = 0; i < my; i++){
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            a[i][j] = str[j];
        }
    }

    idx = a[0][0] - 'A';
    dfs(0, 0, 1, (1 << idx));
    
    cout << ret << "\n";


    return 0;
}