#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tk;
    cin >> tk;
    for (int i = 0; i < tk; i++) {
        int n;
        cin >> n;
        vector<int> v (n + 1, -1);
        vector<int> done (n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cin >> v[j];
        }
        stack<int> s;
        for (int j = 1; j <= n; j++) {
            vector<int> vis (n + 1, 0);
            s.push(v[j]);
            vis[j] = 1;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                
            }
        }
        
        






        for (int j = 1; j <= n; j++) {
            cout << v[j] << " ";
            if (v[j] == 0) {
                cnt++;
            }
        }
        cout <<"\n";
        
        cout << cnt << "\n";
    }

    return 0;
}
