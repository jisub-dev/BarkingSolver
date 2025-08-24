#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    stack<int> st;
    string str;
    int temp = 1;

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push(-1);
            temp *= 2;
        }
        else if (str[i] == '[') {
            st.push(-2);
            temp *= 3;
        }
        else if (str[i] == ')') {
            if (st.empty() || st.top() != -1) {
                ans = 0;
                break;
            }
            if(str[i - 1] == '(') {
                ans += temp;
                temp /= 2;
                st.pop();
            }
            else {
                temp /= 2;
                st.pop();
            }
        }
        else if (str[i] == ']') {
            if (st.empty() || st.top() != -2) {
                ans = 0;
                break;
            }
            if(str[i - 1] == '[') {
                ans += temp;
                temp /= 3;
                st.pop();
            }
            else {
                temp /= 3;
                st.pop();
            }
        }
    }
    if (!st.empty()) ans = 0;
    cout << ans;
    return 0;
}