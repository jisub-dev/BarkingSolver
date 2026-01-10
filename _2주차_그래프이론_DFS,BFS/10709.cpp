#include <bits/stdc++.h>
using namespace std;

int n, m, a[104][104], vis[104][104];
string temp;
int main() {
    cin >> n >> m;
    fill(&vis[0][0], &vis[0][0] + 104 * 104, -1);
    for (int i = 0; i < n; i++){
        cin >> temp;
        for (int j = 0; j < m; j++) {
            a[i][j] = temp[j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if(a[i][j] == 'c') {
                vis[i][j] = 0;
            }
            else {
                if (j>0) {
                    if (vis[i][j-1] > -1) {
                        vis[i][j] = vis[i][j - 1] + 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}