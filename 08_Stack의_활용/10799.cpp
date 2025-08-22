#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    stack<char> st;
    string str = "";
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push('(');
        }
        else {
            if (!st.empty() && str[i - 1] == '(') {
                st.pop();
                ans += st.size();
            }
            else if (!st.empty()) {
                st.pop();
                ans++;
            }
        }
    }

    cout << ans;
    
    return 0;
}
