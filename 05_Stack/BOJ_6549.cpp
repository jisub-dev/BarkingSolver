#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int a[100002];

        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;
        a[n] = 0;
        
        stack<pair<int, long long>> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && st.top().second > a[i]) {
                
                int right = i - 1;
                long long h = st.top().second;

                st.pop();
                int left = st.empty() ? 0 : st.top().first + 1;

                long long width = right - left + 1;
                long long area = h * width;
                if (ans < area) ans = area;
            }
            st.push({i, a[i]});
        }
        cout << ans << "\n";
    }

    return 0;
}
