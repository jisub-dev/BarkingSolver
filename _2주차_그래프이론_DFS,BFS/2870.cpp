#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<string> res;
bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b; // 2순위
    return a.size() < b.size(); // 1순위
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            int flag = 0;
            string temp;
            while (j < str.length() && isdigit(str[j])) {
                temp += str[j];
                j++;
                flag = 1; 
            }
            if (flag) {
                while (1) {
                    if (temp.size() && temp.front() == '0') temp.erase(temp.begin());
                    else break;
                }
                if (temp.size() == 0){
                    res.push_back("0");
                }
                else res.push_back(temp);
            }
        } 
    }
    sort(res.begin(), res.end(), cmp);
    for(auto i : res) {
        cout << i << "\n";
    }
    
    return 0;
}