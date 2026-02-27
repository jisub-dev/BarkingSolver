#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int n, a[14][14], ne, hu[14], ret = INF, vis[14], cnt;

void con(int here, int mask, int team) {
    for(int i = 1; i <= n; i++) {
            if(a[here][i] == 1 && vis[i] == 0 && (mask >> (i-1) & 1) == team) { // i가 team에 속한다
                vis[i] = 1;
                cnt += hu[i];
                con(i, mask, team);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> hu[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> ne;
        for (int j = 0; j < ne; j++) {
            int neb;
            cin >> neb;
            a[i][neb] = 1; // 1이면 인접한 선거구임
            a[neb][i] = 1;
        }
    }

    for(int mask = 1; mask < (1<<n)-1; mask++) {
        fill(vis, vis + 14, 0);
        cnt = 0;
        for(int i = 1; i <= n; i++) {
            if ((mask >> (i-1) & 1) == 1) {
                vis[i] = 1;
                cnt += hu[i];
                con(i, mask, 1);
                break;
            }
        }
        int pre = cnt;
        cnt = 0;
        for(int i = 1; i <= n; i++) {
            if ((mask >> (i-1) & 1) == 0 && vis[i] == 0) {
                vis[i] = 1;
                cnt += hu[i];
                con(i, mask, 0);
                break;
            }
        }
        int gap = abs(cnt - pre);
        for(int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                break;
            }
            if (i == n) {
                ret = min(ret, gap);
            }
        }
    }

    if(ret == INF) cout << "-1\n";
    else cout << ret << "\n";

    return 0;
}