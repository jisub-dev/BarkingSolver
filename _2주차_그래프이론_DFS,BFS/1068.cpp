#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int root, temp, n, rm, cnt;

void DFS(int node) {
    if (node == rm) {
        return;
    }
    int isLeaf = 0;
    for (auto i : v[node]) {
        if (i != rm) {
            isLeaf++;
        }
    }
    if (isLeaf == 0) {
        cnt++;
        return;
    }
    for (auto i : v[node]) {
        DFS(i);
    }
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if(temp == -1) {
            root = i;
        }
        else {
            v[temp].push_back(i);
        }
    }
    cin >> rm;
    DFS(root);
    cout << cnt;

    return 0;
}