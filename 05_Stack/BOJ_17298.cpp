#include <bits/stdc++.h>
using namespace std;
vector<int> v;
stack<int> s;

void insert(){
    for(int i = 0; i < repeat; i++){
        if(s.top() < v[i]){
            s.push(v[i]);
            cout << s.top();
        }
        else if(s.top() >= v[i]){
            insert();
            cout s.top();
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int repeat;
    cin >> repeat;
    
    

    for(int i = 0; i < repeat; i++){
        int a;
        cin >> a; 
        v.push_back(a);
    }

    
    insert();
    
    return 0;
}
