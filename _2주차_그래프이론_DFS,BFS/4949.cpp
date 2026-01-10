#include <bits/stdc++.h>
using namespace std;

string str;
int main() {
    while (getline(cin, str) && str != ".") {
        stack<char> s;
        int flag = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            }
            else if (str[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    flag = 1;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    flag = 1;
                    break;
                }
            }
        }
        if (!s.empty()) {
            flag = 1;
        }
        if (flag) cout << "no\n";
        else cout << "yes\n"; 
    }

    return 0;
}