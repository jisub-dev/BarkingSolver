#include<bits/stdc++.h>
using namespace std;

string st, ed;
void split(const string& input, char delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + sizeof(delimiter);
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    st = result[0];
    ed = result[1];
}

int main() {
    int n; 
    cin >> n;
    string se;
    cin >> se;
    split(se, '*');
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str.length() < st.length() + ed.length()) cout << "NE\n";
        else if (str.substr(0, st.length()) == st) {
            if (str.substr(str.length() - ed.length(), ed.length()) == ed) {
                cout << "DA\n";
            } else cout << "NE\n";
        } else cout << "NE\n";
    }

    return 0;
}