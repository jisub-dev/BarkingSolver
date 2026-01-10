#include <bits/stdc++.h>
using namespace std;

int tim1, tim2, s, pre, s1, s2, n, win;
string tim;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        
        cin >> win;
        cin >> tim;
        string mm;
        mm += tim[0];
        mm += tim[1];
        string ss;
        ss += tim[3];
        ss += tim[4];
        int temm, tems;
        temm = stoi(mm);
        tems = stoi(ss);
        tems += (temm * 60);
        s = tems;
        int gap;
        
        gap = s - pre;
        pre = s;
        
        if(s1 > s2){
            tim1 += gap;
        } else if (s1 < s2) {
            tim2 += gap;
        }
        
        if (win == 1) s1++;
        else s2++;
    }
    s = 60 * 48 - pre;
    if(s1 > s2){
        tim1 += s;
    } else if (s1 < s2) {
        tim2 += s;
    }

    string mm1 = to_string(tim1 / 60);
    if (mm1.length() == 1) {
        mm1.insert(0, "0");
    }
    string ss1 = to_string(tim1 % 60);
    if (ss1.length() == 1) {
        ss1.insert(0, "0");
    }
    string mm2 = to_string(tim2 / 60);
    if (mm2.length() == 1) {
        mm2.insert(0, "0");
    }
    string ss2 = to_string(tim2 % 60);
    if (ss2.length() == 1) {
        ss2.insert(0, "0");
    }

    cout << mm1 << ":" << ss1 << "\n";
    cout << mm2 << ":" << ss2 << "\n";

    return 0;
}