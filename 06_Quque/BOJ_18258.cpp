#include <bits/stdc++.h>
using namespace std;

int n;
string str;
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> str;
        if (str == "push") {
            int val;
            cin >> val;
            q.push(val);
        }
        else if (str == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            } 
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (str == "size") {
            cout << q.size() << "\n";
        }
        else if (str == "empty") {
            cout << q.empty() << "\n";
        }
        else if (str == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        else if (str == "back") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}
