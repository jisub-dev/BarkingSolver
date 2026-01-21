#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
const int INF = 1e9;
int n, total, a[14][14], vis[14][14], ret = INF;

bool check(int y, int x) {
    if(vis[y][x] == 1) return false; 
    for(int i = 0;i < 4; i++){  
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= n || nx < 0 || vis[ny][nx] == 1) return false;
    }
    return true;
}

int setFlower(int y, int x) {
    int cost = a[y][x];
    vis[y][x] = 1;
    for(int i = 0;i < 4; i++){  
        int ny = y + dy[i];
        int nx = x + dx[i];
        vis[ny][nx] = 1;
        cost += a[ny][nx];
    }
    return cost;
}

void eraseFlower(int y, int x) {
    vis[y][x] = 0;
    for(int i = 0;i < 4; i++){  
        int ny = y + dy[i];
        int nx = x + dx[i];
        vis[ny][nx] = 0;
    }
}

void flower(int cnt, int cost) {
    if (cnt == 3) {
        ret = min(ret, cost);
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            if(check(i, j)) {
                flower(cnt + 1, cost + setFlower(i, j));
                eraseFlower(i, j);
            }
        }
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    flower(0, 0);
    cout << ret << "\n";

    return 0;
}