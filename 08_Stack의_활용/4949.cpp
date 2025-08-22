#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str = "";
    while (true) {
        bool err = false;
        stack<char> st;

        getline(cin, str);
        if (str == ".") {
            break;
        }

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '[') {
                st.push('[');
            }
            else if (str[i] == '(') {
                st.push('(');
            }
            else if (str[i] == ')') {
                if (st.empty() || st.top() != '(') {
                    err = true;
                    break;
                }
                else {
                    st.pop();
                }
            }
            else if (str[i] == ']') {
                if (st.empty() || st.top() != '[') {
                    err = true;
                    break;
                }
                else {
                    st.pop();
                }
            }
        }
        if (err || !st.empty()) {
            cout << "no\n";
        }
        else {
            cout << "yes\n";
        }
    }


    return 0;
}
