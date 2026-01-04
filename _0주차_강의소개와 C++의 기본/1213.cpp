#include <bits/stdc++.h>
using namespace std;

int alp[26];
int temp;
int odd;
string ans, input;
char chtemp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> input;
    for (int i = 0; i < input.length(); i++){
        temp = input[i] - 'A';
        alp[temp]++;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++) {
        if (1 == alp[i] % 2){
            flag++;
            odd = i;
        }
    }
    if (flag > 1) {
        cout << "I'm Sorry Hansoo";
        exit(0);
    }
    for (int i = 0; i < 26; i++) {
        while (alp[i] > 1) {
            alp[i] -= 2;
            chtemp = (char)(i + 'A');
            ans += chtemp;
        }
    }
    cout << ans;
    if (flag) {
        cout << (char)(odd + 'A');
    }
    reverse(ans.begin(), ans.end());
    cout << ans;


    return 0;
}