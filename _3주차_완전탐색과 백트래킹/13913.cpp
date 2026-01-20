#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
int vis[200004], parent[200004];

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    fill(&vis[0], &vis[0] + 200004, -1);
    cin >> n >> k;
    if (n == k) {
        cout << "0\n" << k << "\n";
        return 0; 
    }
    q.push(n);
    vis[n] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : {cur - 1, cur + 1, cur * 2}) {
            if(i <= 100000 && i >= 0) {
                if (vis[i] == -1) {
                    vis[i] = vis[cur] + 1;
                    parent[i] = cur;
                    q.push(i);
                    if (i == k) {
                        cout << vis[i]<< "\n";
                        stack<int> s; // 이거대신 벡터 reverse 써도 됨
                        int find = k;
                        while (true) {
                            s.push(find);
                            find = parent[find];
                            if (find == n) {
                                break;
                            }
                        }
                        s.push(n);
                        while (!s.empty()){
                            cout << s.top() << " ";
                            s.pop();
                        }
                        cout << "\n";
                        exit(0);
                    }
                }
                
            }
        }
    }

    return 0;
}