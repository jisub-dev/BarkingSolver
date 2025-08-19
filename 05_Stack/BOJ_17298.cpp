#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int ans[1000001];
int n;
stack<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a; 
        v.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
