#include <bits/stdc++.h>
using namespace std;

int n, k, vis[500004][2], d;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    fill(&vis[0][0], &vis[0][0] + 500004 * 2, -1);
    cin >> n >> k;
    if (n == k) {
        cout << "0\n";
        exit(0);
    }
    q.push(n);
    vis[n][0] = 0;
    while(!q.empty()) {
        int sz = q.size();
        d++;
        k += d;
        for (int s = 0; s < sz; s++) {
            int cur = q.front();
            q.pop();
            for (int i : {cur + 1, cur - 1, cur * 2}) {
                
                if (i <= 500000 && i > -1) {
                    if (vis[i][d % 2] == -1) {
                        q.push(i);
                        vis[i][d % 2] = d;
                        
                    }
                }
            }
        }
        
        if (k > 500000) {
            cout << "-1\n";
            exit(0); 
        }
        if (vis[k][d % 2] != -1) {
            cout << d;
            exit(0);
        }
        
    }
    

    return 0;
}