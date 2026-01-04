#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    for(auto i : str) {
        if (i >= 'A' && i <= 'Z') cout << (char)((((i - 'A') + 13) % 26) + 'A'); 
        else if (i >= 'a' && i <= 'z') cout << (char)((((i - 'a') + 13) % 26) + 'a'); 
        else cout << i;
    }

    return 0;
}