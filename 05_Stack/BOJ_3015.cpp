#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
stack<pair<int, int>> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int h = a[i];
        int same = 0;

        // 작은 키 제거
        while (!st.empty() && st.top().first < h) {
            ans += st.top().second;
            st.pop();
        }
        
        // 같은 키 묶음
        if (!st.empty() && st.top().first == h) {
            ans += st.top().second;
            same = st.top().second;
            st.pop();
        }

        // 앞에서 먼저 들어갔던 사람 중 h보다 더 큰 사람 1명은 무조건 보임
        if (!st.empty()) {
            ans++;
        }

        st.push({h, same + 1});
    }

    cout << ans << "\n";


    return 0;
}
