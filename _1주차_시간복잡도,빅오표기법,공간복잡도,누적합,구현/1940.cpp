#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
long long ans;
int arr[1000004];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr[temp] = 1;
    }
    for (int i = 1; i < m - i; i++) {
        if (arr[i] && arr[m - i]) {
            arr[m - i] = 0;
            ans++;
        }
    }
    cout << ans;
    return 0;
}