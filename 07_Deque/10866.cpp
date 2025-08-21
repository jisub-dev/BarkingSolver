#include <bits/stdc++.h>
using namespace std;

int n;
string str;
deque<int> dq;
int num;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> str;

        if (str == "push_front") {
            cin >> num;
            dq.push_front(num);
        }
        else if (str == "push_back") {
            cin >> num;
            dq.push_back(num);
        }
        else if (str == "pop_front") {
            if (dq.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (str == "pop_back") {
            if (dq.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (str == "size") {
            cout << dq.size() << "\n";
        }
        else if (str == "empty") {
            cout << dq.empty() << "\n";
        }
        else if (str == "front") {
            int re = dq.empty() ? -1 : dq.front();
            cout << re << "\n";
        }
        else if (str == "back") {
            int re = dq.empty() ? -1 : dq.back();
            cout << re << "\n";
        }
    }

    return 0;
}
