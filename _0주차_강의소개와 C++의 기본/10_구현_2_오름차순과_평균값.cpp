#include<bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> v;
double b;

int main() {
    cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        b += temp;
        v.push_back(temp);
    }
    double avarage = b / n;

    // 정렬된 배열
    sort(v.begin(), v.end());
    for (auto i : v) cout << i << " ";
    cout << "\n";

    // 배열의 평균값
    //소수점 두번째 자리까지 출력
    cout << fixed << setprecision(2) << avarage << "\n";

    return 0;
}