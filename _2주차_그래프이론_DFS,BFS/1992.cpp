#include <bits/stdc++.h>
using namespace std;

int n;
string str, temp;
int a[64][64];
void DFS(int sy, int sx, int ey, int ex) {
    int st = a[sy][sx];
    for (int i = sy; i < ey; i++) {
        for (int j = sx; j < ex; j++) {
            if (st != a[i][j]) {
                str.push_back('(');
                int midY = (sy + ey) / 2;
                int midX = (sx + ex) / 2;
                DFS(sy, sx, midY, midX);
                DFS(sy, midX, midY, ex);
                DFS(midY, sx, ey, midX);
                DFS(midY, midX, ey, ex);
                str.push_back(')');
                return;
            }
        }
    }
    char ch = st + '0';
    str.push_back(ch);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < temp.length(); j++) {
            char ch = temp[j] - '0';
            a[i][j] = ch;
        }
    }
    DFS(0, 0, n, n);
    cout << str << "\n";

    return 0;
}