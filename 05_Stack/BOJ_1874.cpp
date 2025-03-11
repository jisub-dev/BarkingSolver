#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int repeat;
    cin >> repeat;

    vector<char> V;

    stack<int> S;
    int m = 1;
    int err = 0;

    for(int i = 0; i < repeat; i++)
    {
        int num;
        cin >> num;
        while(num >= m)
        {
            S.push(m);
            V.push_back('+');
        }
        S.pop();
        V.push_back('-');
    }


    return 0;
}
