// #include <bits/stdc++.h>
// using namespace std;

// int n, k, sum = 0, mx = 0, input;
// vector<int> v;

// int main() {
//     cin >> n >> k;
//     for (int i = 0; i < n; i++) {
//         cin >> input;
//         v.push_back(input);
//     }
//     for (int i = 0; i < k; i++) {
//         sum += v[i];
//     }
//     mx = sum;
//     for (int i = 0; i + k < n; i++) {
//         sum += v[i + k];
//         sum -= v[i];
//         if (mx < sum) {
//             mx = sum;
//         }
//     }
//     cout << mx;

//     return 0;
// }



/*
큰돌 버전
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, temp, psum[100001], ret = - 10000004; // 세그멘테이션 방지 버퍼 설정
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> temp; psum[i] = psum[i - 1] + temp;
    }
    for (int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i - k]);
    }
    cout << ret << "\n";
    return 0;
}