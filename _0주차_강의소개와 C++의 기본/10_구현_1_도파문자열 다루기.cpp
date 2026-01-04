#include<bits/stdc++.h>
using namespace std;

void print(string txt) {
    cout << txt << "\n";
}

int main() {

    // string dopa = "umzunsik";
    // //Q1. 앞에서부터 3개의 문자열을 출력하라
    // for (int i = 0; i < 3; i++) {
    //     cout << dopa[i];
    // }
    // cout << "\n";
    
    // //Q2. 해당 문자열을 거꾸로 해서 출력하라.
    // reverse(dopa.begin(), dopa.end());
    // cout << dopa << "\n";
    // //Q3. 거꾸로된 해당 문자열 끝에 "umzunsik"이란 문자열을 추가하라.
    // string rev = dopa;
    // reverse(dopa.begin(), dopa.end());
    // rev.append(dopa);
    // cout << rev;

    string dopa = "umzunsik";
    //Q1. 앞에서부터 3개의 문자열을 출력하라
    string dopa2 = dopa.substr(0, 3);
    print(dopa2);
    //Q2. 해당 문자열을 거꾸로 해서 출력하라.
    reverse(dopa2.begin(), dopa2.end());
    print(dopa2);
    //Q3. 거꾸로된 해당 문자열 끝에 "umzunsik"이란 문자열을 추가하라.
    dopa2 += "umzunsik";
    print(dopa2);


    return 0;
}