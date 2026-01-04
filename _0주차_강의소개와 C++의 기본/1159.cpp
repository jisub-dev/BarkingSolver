#include<bits/stdc++.h>
using namespace std;

vector<char> v;
int cnt[26];
bool flag;
int main() {
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        int index = (int)str[0] - 'a';
        cnt[index]++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            v.push_back((char)i + 'a');
            flag = 1;
        }
    }
    if (!flag) {
        cout << "PREDAJA";
        return 0;
    }
    sort(v.begin(), v.end());
    for (char i : v) cout << i;
    return 0;
}