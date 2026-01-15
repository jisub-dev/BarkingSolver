#include <bits/stdc++.h>
using namespace std;

int n, m, temp, result = 987654321;
vector<vector<int>> chickenList;
vector<pair<int, int>> chi, hom;

void combi(int start, vector<int> v){
    if (v.size() == m) {
        chickenList.push_back(v);
        return;
    }
    for (int i = start + 1; i < chi.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp == 1) {
                hom.push_back({i, j});
            }
            else if (temp == 2) {
                chi.push_back({i, j});
            }
        }
    }
    vector<int> v;
    combi(-1, v);
    for (vector<int> cList : chickenList) {
        int ret = 0;
        for (pair<int, int> home : hom) {
            int _min = 987654321;
            for (int ch : cList) {
                int _dist = abs(home.first - chi[ch].first) + abs(home.second - chi[ch].second);
                _min = min(_min, _dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }
    cout << result << "\n";

    

    return 0;
}