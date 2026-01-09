#include <bits/stdc++.h>
using namespace std;

int n, m, bas, bae, k, res;
int main() {
    cin >> n >> m >> k;
    bas = 1;
    bae = m;

    for (int i = 0; i < k; i++) {
        int tg;
        cin >> tg;
        while (tg < bas || tg > bae) {
            res++;
            if (tg < bas) {
                bas--;
                bae--;
            }
            else {
                bas++;
                bae++;
            }
        }
    }
    cout << res << "\n";

    return 0;
}