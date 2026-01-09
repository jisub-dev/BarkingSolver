#include <bits/stdc++.h>
using namespace std;

int divi, gather, flag;
string str;
int main() {
    cin >> str;
    while (str != "end"){
        divi = 0; gather = 0; flag = 0; 
        for (int i = 0; i < str.length(); i++) {
            if (!gather) {
                if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                    gather = 1;
                }
            }

            if (i > 0) {
                if (str[i] != 'e' && str[i] != 'o') {
                    if (str[i] == str[i-1]) {
                        cout << "<" << str << "> is not acceptable.\n";
                        flag = 1;
                        break;
                    }
                }
                
            }

            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ) {
                if (divi < 0) { //음수 였다면 (자음 이었다면)
                    divi = 1;
                } else divi++;
            }
            else {
                if (divi > 0) { // 양수 였다면 (모음 이었다면)
                    divi = -1;
                } else divi--;
            }
            if (divi >= 3 || divi <= -3) {
                cout << "<" << str << "> is not acceptable.\n";
                flag = 1;
                break;
            }
        }
        if (gather && !flag){
            cout << "<" << str << "> is acceptable.\n";
        }
        if (!gather && !flag){
            cout << "<" << str << "> is not acceptable.\n";
        }
        
        cin >> str;
    }

    return 0;
}