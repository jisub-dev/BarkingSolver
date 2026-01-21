#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, h, a[304][304], len, ver, ret;

bool check() {
    for(int i = 1; i <= n; i++) {
        int x = i;
        for (int y = 1; y <= h; y++){ 
            if(a[y][x] == 1) {
                x++;
            }
            else if (x > 1 && x <= n && a[y][x - 1] == 1) {
                x--;
            }
        }
        if(i != x) return false;
    }
    return true;
}

void go(int here, int cnt) {
    if (cnt > 3 || cnt >= ret) return; 
    if (check()){
        ret = min(ret, cnt);
        return;
    }
    for(int i = here; i <= h; i++) {
        for(int j = 1; j < n; j++) {
            if(a[i][j] || a[i][j - 1] || a[i][j + 1]) continue;
            a[i][j] = 1;
            go(i, cnt + 1);
            a[i][j] = 0;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ret = INF;
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> len >> ver;
        a[len][ver] = 1;
    }
    go(1, 0);
    if (ret == INF) cout << "-1\n";
    else cout << ret << "\n";

    return 0;
}