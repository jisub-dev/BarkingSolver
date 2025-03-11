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
        string str;
        cin >> str;
        if(str == "push")
        {
            int num;
            cin >> num;
            S.push(num);
        }
        else if(str == "pop")
        {
            if(!S.empty())
            {
                cout << S.top() << "\n";
                S.pop();
            }
            else
            {
                cout << "-1\n";
            }

        }
        else if(str == "size")
        {
            cout << S.size() << "\n";
        }
        else if(str == "empty")
        {
            cout << S.empty() << "\n";
        }
        else if(str == "top")
        {
            if(!S.empty()){
                cout << S.top() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
    }


    return 0;
}
