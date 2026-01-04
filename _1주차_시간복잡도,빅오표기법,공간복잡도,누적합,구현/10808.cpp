#include<bits/stdc++.h>
using namespace std;
string str;
int alpha[26];

int main() {
    cin >> str;
    for (auto i : str) {
        int index = (int)i - 97;
        alpha[index]++;
    }
    for (auto i : alpha) {
        cout << i << " ";
    }
    return 0;
}