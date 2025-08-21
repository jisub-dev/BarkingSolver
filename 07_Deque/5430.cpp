#include <bits/stdc++.h>
using namespace std;

int t;
string p;
int n;
string str;
deque<int> dq;
bool err;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        err = false;
        bool rev = false;
        cin >> p;
        cin >> n;
        cin >> str;
        string temp;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ',' || str[i] == ']') {
                if (temp != ""){
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
            else if (isdigit(str[i])) {
                temp += str[i];
            }
        }
        
        for (int i = 0; i < p.size(); i++) {
            
            if (p[i] == 'R') {
                rev = rev ? false : true; 
            }
            else {
                if (dq.empty()) {
                cout << "error\n";
                err = true;
                break;
                }
                if (!rev) 
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if (!err) {
            cout << "[";
            if (!rev) {
                for (int i = 0; i < dq.size(); i++){
                    cout << dq[i];
                    if (i < dq.size() - 1) cout << ",";
                }
            }
            else {
                for (int i = dq.size() - 1; i >= 0; i--){
                    cout << dq[i];
                    if (i > 0) cout << ",";
                }
            }
            cout << "]\n" ;
            
        }
        dq.clear();
    }

    return 0;
}
