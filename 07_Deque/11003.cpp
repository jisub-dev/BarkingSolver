#include <bits/stdc++.h>
using namespace std;

int n;
int l;
deque<pair<int, int>> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        // 이전 값이 새로 삽입되는 값보다 작다면 pop_back 을 통해 front가 항상 최소값임을 유지함
        while (!dq.empty() && dq.back().first >= temp) {
            dq.pop_back();
        }

        dq.push_back({temp, i});

        if (dq.front().second <= i - l ) {
            dq.pop_front();
        }

        cout << dq.front().first << " ";
    }

    return 0;
}
