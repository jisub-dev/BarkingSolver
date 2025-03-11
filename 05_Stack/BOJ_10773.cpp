#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;

    int repeat;
    cin >> repeat;
    for(int i = 0; i < repeat; i++)
    {
        int num;
        cin >> num;
        if(num == 0)
        {
            S.pop();
        }
        else
        {
            S.push(num);
        }
    }

    int result = 0;
    while(!S.empty())
    {
        result += S.top();
        S.pop();
    }
    cout << result;

    return 0;
}
