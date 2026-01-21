#include <bits/stdc++.h>
using namespace std;

int a[100004];
int k;
vector<vector<int>> v;

void go(int s, int e, int lev) {
    if (s > e) {
        return;
    }
    if (s == e) {
        v[lev].push_back(a[s]);
    }
    else {
        int mid = (s + e) / 2;
        go(s, mid - 1, lev + 1);
        v[lev].push_back(a[mid]);
        go(mid + 1, e, lev + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    v.assign(k + 1, vector<int>(0, 0));
    int _end = (int)pow(2, k) - 1;
    for (int i = 0; i < _end; i++) {
        cin >> a[i];
    }

    go(0, _end - 1, 1);
    for (int i = 1; i <= k; i++) {
        for (int j : v[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }


    return 0;
}