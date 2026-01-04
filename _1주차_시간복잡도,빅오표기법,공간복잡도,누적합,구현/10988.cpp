#include<bits/stdc++.h>
using namespace std;

string str;
int main() {
    cin >> str;
    int ed = str.length();
    for (int i = 0; i < ed/2; i++){
        if (str[i] != str[ed - 1 - i]) {
            cout << "0";
            return 0;    
        }
    }
    cout << "1";
    return 0;
}