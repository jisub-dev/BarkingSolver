#include <bits/stdc++.h>
using namespace std;

int n, ans;
string str;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        stack<char> s;
        for (int j = 0; j < str.length(); j++){ 
            s.push(str[j]);
            while (!s.empty() && j < str.length() - 1 && s.top() == str[j+1]) {
                j++;
                s.pop();
            }
        }
        if (s.empty()) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}