#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int m = n;
    int i = 1;

    while (m--) {
        q.push(i++);
    }

    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();

    return 0;
}
