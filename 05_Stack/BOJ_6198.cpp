#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    int n;
    cin >> n;

    stack<int> st;
    long long cnt = 0;

    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;

        if (st.empty()) {
            st.push(in);
        } else {
            while (!st.empty() && st.top() <= in) {
                st.pop();
            }
            cnt += st.size();
            st.push(in);
        }   
    }
    
    cout << cnt;

    return 0;
}
