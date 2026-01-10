#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int res2 = 0, res5 = 0;
        for (int j = 2; j <= n; j *= 2) {
            res2 += n / j;
        }
        // 팩토리얼에서 2의 개수는 5보다 항상 많아서 2의 개수를 셀 필요가 없음
        for (int j = 5; j <= n; j *= 5) {
            res5 += n / j;
        }
        cout << min(res2, res5) << "\n";
    }

    return 0;
}