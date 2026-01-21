#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int r, c, k, vis[10][10], mn, dis[1004], res;
string str;
char a[10][10];

void DFS(int y, int x, int cnt){
    if(y == 0 && x == c - 1) {  
        if (cnt == k) res++;
        return;
    }
    if(cnt > k){
        return;
    }
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < r && ny > -1 && nx < c && nx > -1 && vis[ny][nx] == 0 && a[ny][nx] == '.') {
            vis[ny][nx] = 1;
            DFS(ny, nx, cnt + 1);
            vis[ny][nx] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> k;
    for(int i = 0; i < r; i++) {
        cin >> str;
        for(int j = 0; j < c; j++) {
            a[i][j] = str[j];
        }
    }
    for(int i = r - 1; i > -1; i--) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] == '.') {
                vis[i][j] = 1;
                DFS(i, 0, 1);
                i = -1; j = c;
            }
        }
    }
    cout << res << "\n";


    return 0;
}