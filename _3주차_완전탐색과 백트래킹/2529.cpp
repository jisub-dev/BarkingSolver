#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int k, flag;
char seq[14];
int alph[14];

void de_DFS(int x, int cnt) {
    if (flag) return;
    if (cnt == k + 1) {
        for (int i : v) {
            cout << i;
        }
        cout << "\n";
        flag = 1;
        return;
    }
    if (seq[cnt - 1] == '<') {
        for (int i = 9; i >= x + 1; i--) {
            if(alph[i] == 0) {
                v.push_back(i);
                alph[i] = 1;
                de_DFS(i, cnt + 1);
                alph[i] = 0;
                v.pop_back();
            }
        } 
    }
    else {
        for (int i = x - 1; i >= 0; i--) {
            if(alph[i] == 0) {
                v.push_back(i);
                alph[i] = 1;
                de_DFS(i, cnt + 1);
                alph[i] = 0;
                v.pop_back();
            }
        }
    }
}

void in_DFS(int x, int cnt) {
    if (flag) return;
    if (cnt == k + 1) {
        for (int i : v) {
            cout << i;
        }
        cout << "\n";
        flag = 1;
        return;
    }
    if (seq[cnt - 1] == '<') {
        for (int i = x + 1; i <= 9; i++) {
            if(alph[i] == 0) {
                v.push_back(i);
                alph[i] = 1;
                in_DFS(i, cnt + 1);
                alph[i] = 0;
                v.pop_back();
            }
        } 
    }
    else {
        for (int i = 0; i <= x - 1; i++) {
            if(alph[i] == 0) {
                v.push_back(i);
                alph[i] = 1;
                in_DFS(i, cnt + 1);
                alph[i] = 0;
                v.pop_back();
            }
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> seq[i];
    }

    for (int i = 9; i >= 0; i--) {
        v.push_back(i);
        alph[i] = 1;
        de_DFS(i, 1);
        v.pop_back();
        alph[i] = 0;
    }
    flag = 0;
    v.clear();
    fill(&alph[0], &alph[0] + 14, 0);
    for (int i = 0; i <= 9; i++) {
        v.push_back(i);
        alph[i] = 1;
        in_DFS(i, 1);
        v.pop_back();
        alph[i] = 0;
    }

    return 0;
}