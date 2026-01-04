#include <bits/stdc++.h>
using namespace std;
int cnt[100];
int main() {
    int result = 0;
    int a, b, c;
    cin >> a >> b >> c;
    int st, ed;
    for(int i = 0; i < 3; i++) {
        cin >> st >> ed;
        for (int j = st; j < ed; j++) {
            cnt[j]++;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (cnt[i]) { 
            if (cnt[i] == 1) result += a;
            else if (cnt[i] == 2) result += b * 2;
            else if (cnt[i] == 3) result += c * 3;
        }
    }
    cout << result;

    return 0;
}