#include <bits/stdc++.h>
using namespace std;

int n, k, rec;
int dist[100004], cnt[100004];
queue<int> q;

int main() {
    cin >> n >> k;
    cnt[n] = 1;
    if (n == k) {
        cout << "0\n1\n";
        return 0;
    }
    fill(&dist[0], &dist[0] + 100004, -1);

    dist[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if(dist[k] != -1 && dist[cur] > dist[k]) break;
        
        for (int i = 0; i < 3; i++) {
            int nn;
            if (i == 0) {
                nn = cur + 1;
            }
            else if (i == 1) {
                nn = cur - 1;
            }
            else if (i == 2) {
                nn = cur * 2;
            }
            
            if (nn <= 100000 && nn >= 0) {
                if (dist[nn] == -1) {
                    dist[nn] = dist[cur] + 1;
                    q.push(nn);
                    cnt[nn] = cnt[cur];
                }
                else if(dist[nn] == dist[cur] + 1) {
                    cnt[nn] += cnt[cur];
                }
            }
        }   
    }

    cout << dist[k] << "\n" << cnt[k] << "\n";

    return 0;
}