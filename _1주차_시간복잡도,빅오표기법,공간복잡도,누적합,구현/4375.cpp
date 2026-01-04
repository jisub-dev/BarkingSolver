#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int mem = 1 % n;
        int cnt = 1;
        while (mem != 0) {
            cnt++;
            mem = (mem * 10 + 1) % n;
        }
        cout << cnt << "\n";
    }

    return 0;
}