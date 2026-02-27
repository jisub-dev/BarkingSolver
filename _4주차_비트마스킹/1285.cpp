#include <bits/stdc++.h>
using namespace std;

int n, a[44], ret=1e9;
char ch;

void go(int here) {
    if (here == n + 1) { // 마지막 열에 도달하면 그때 판단 
        int sum = 0;
        for (int i = 1; i <= (1 << (n - 1)); i <<= 1) { // 해당 열만 보기 위한 비트마스킹
            int cnt = 0;
            for (int j = 1; j <= n; j++) { // 각 열에 T가 몇개있는지 카운트 -> 모이면 전체 원소중에 T가 몇개있는지 세게 됨
                if (a[j] & i) { // 보려고 하는 인덱스에 1이 있는지 (T가 해당 인덱스에 존재 하는지 체크, 있으면 셈)
                    cnt++; // 카운트
                }
            }
            sum += min(cnt, n - cnt); // 그냥 T의 개수 카운트 vs 해당 행의 총 개수 - T의 카운트 (뒤집었을때 T의 개수) -> 중에 작은거 고름
        }
        ret = min(ret, sum); 
        return;
    }
    go(here + 1);
    a[here] = ~a[here];
    go(here + 1);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val = 1;
        for (int j = 0; j < n; j++) {
            cin >> ch;
            if (ch == 'T') {
                a[i] |= val;
            }
            val *= 2;
        }
    }
    go(1);
    cout << ret << "\n";


    return 0;
}