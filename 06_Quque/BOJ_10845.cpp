#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        
        string in;
        cin >> in;

        if (in == "push") {
                int num;
                cin >> num;
                q.push(num);
        }
        else if (in == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else { 
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (in == "size") {
            cout << q.size() << "\n";
        }
        else if (in == "empty") {
            cout << q.empty() << "\n";
        }
        else if (in == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else
                cout << q.front() << "\n";
        }
        else if (in == "back") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else
                cout << q.back() << "\n";
        }
    } 

    return 0;
}
