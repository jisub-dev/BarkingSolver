#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;
int b, c, d, e, ret = INF, sum;
int n, mp, mf, ms, mv;
struct A {
    int mp, mf, ms, mv, price;
} a[16];
map<int, vector<vector<int>>> res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++) {
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].price;
    }

    for(int i = 1; i < (1 << n); i++) { // 공집합 제외하기 위해선 1부터 시작
        b = c = d = e = sum = 0;
        vector<int> v;
        for(int j = 0; j < n; j++) { 
            if(i & (1 << j)) {  
                v.push_back(j + 1);
                b += a[j].mp;
                c += a[j].mf;
                d += a[j].ms;
                e += a[j].mv;
                sum += a[j].price;
                
            }
        }
        if (b >= mp && c >= mf && d >= ms && e >= mv)
        {
            if (ret >= sum)
            {
                ret = sum;
                res[sum].push_back(v);
            }
        }
    }

    if(ret == INF) {
        cout << "-1\n";
        return 0;
    }

    sort(res[ret].begin(), res[ret].end());
    cout << ret << "\n";
    for(int i : res[ret][0]) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}