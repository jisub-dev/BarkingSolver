#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int repeat;
    cin >> repeat;

    vector<int> V;
    for(int i = 0; i < repeat; i++){
        int num;
        cin >> num;
        V.push_back(num);
    }
    vector<int> sum;
    for(int i = 0; i < V.size(); i++){
        for(int j = i; j < V.size(); j++){
            sum.push_back(V[i] + V[j]); // x+y 조합 저장
        }
    }
    sum.erase(unique(sum.begin(), sum.end()), sum.end()); // 중복 합 제거
    sort(sum.begin(), sum.end());
    int end = 0;
    sort(V.begin(), V.end()); // 집합 정렬
    for(int i = V.size(); i > 0 && end == 0; i--){
        for(int j = i; j >= 0 && end == 0; j--){
            if(binary_search(sum.begin(), sum.end(), (V[i] - V[j]))){ // 존재하면
                cout << V[i];
                end = 1;
                break;
            }   
        }
    }

    return 0;
}
