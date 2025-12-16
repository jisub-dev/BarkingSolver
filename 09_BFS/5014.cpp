#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    vector<int> v (f + 1, -1);
    queue<int> q;
    if (s == g) {
        cout << 0;
        return 0;
    }
    q.push(s);
    v[s] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int ss = cur + u;
        if (ss > 0 && ss <= f && v[ss] == -1) {
            if (ss == g) {
                cout << v[cur] + 1;
                return 0;
            }
            q.push(ss);
            v[ss] = v[cur] + 1;
        } 
        ss = cur - d;
        if (ss > 0 && ss <= f && v[ss] == -1) {
            if (ss == g) {
                cout << v[cur] + 1;
                return 0;
            }
            q.push(ss);
            v[ss] = v[cur] + 1;
        } 
    }
    cout << "use the stairs";
    
    return 0;
}
