#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        stack<char> s;
        int flag = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(') {
                s.push('(');
            }
            else if (!s.empty() && str[j] == ')') {
                s.pop();
            }
            else if (str[j] == ')' && s.empty()) {
                flag = 1;
                break;
            }
        }
        if (!s.empty()) flag = 1;
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}