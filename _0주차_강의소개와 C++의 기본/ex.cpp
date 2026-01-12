#include <bits/stdc++.h>
using namespace std;

int main() {


    vector<int> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }


    map<int, int> mp;
    vector<int> v {1, 1, 2, 2, 3, 3};
    for (int i : v) {
        if (mp[i]) {
            continue;
        } else {
            mp[i] = 1;
        }
    }
    vector<int> ret;
    for (auto it : mp) {
        ret.push_back(it.first);
    }
    for (int i : ret) cout << i << '\n';

    





    return 0;
}

vector<string> split(const string& input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}
