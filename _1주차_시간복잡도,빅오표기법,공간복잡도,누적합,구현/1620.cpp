#include <bits/stdc++.h>
using namespace std;

int n, m, intemp;
string stemp;
vector<string> v;
unordered_map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> stemp;
        v.push_back(stemp);
        mp[stemp] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> stemp;
        if (!isalpha(stemp[0])) {
            intemp = atoi(stemp.c_str());
            cout << v[intemp - 1] << "\n";
        }
        else {
            cout << mp[stemp] << "\n";
        }
    }

    return 0;
}