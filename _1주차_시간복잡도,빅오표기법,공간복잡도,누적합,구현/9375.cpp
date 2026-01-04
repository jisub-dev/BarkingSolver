#include <bits/stdc++.h>
using namespace std;

int t, n;
string nm, ca;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        map<string, int> mp;
        for (int j = 0; j < n; j++) {
            cin >> nm >> ca;
            mp[ca]++;
        }
        long long ret = 1;
        for (auto c : mp) {
            ret *= (long long)c.second + 1;
        }
        ret--;
        cout << ret << "\n";

    }

    return 0;
}