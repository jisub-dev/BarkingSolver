#include <bits/stdc++.h>
using namespace std;

int n, temp, input;
stack<pair<int, int>> s;
vector<int> v;

int main(){
    cin >> n;
    v.resize(n, -1);
    cin >> temp;
        s.push({temp, 0});
    for (int i = 1; i < n; i++) {
        cin >> input;
        while (!s.empty() && s.top().first < input) {
            v[s.top().second] = input;
            s.pop();
        }
        s.push({input, i});
    }
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    return 0;
}