#include <bits/stdc++.h>
using namespace std;
const int N = 3;
const int dy[] = {1, 0, -1 ,0};
const int dx[] = {0, 1, 0, -1};
int arr[N][N];
int vis[N][N];

int main () {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            if(!vis[i][j] && arr[i][j]) {
                q.push({i, j});
                vis[i][j] = 1;
                while(!q.empty()) {
                    auto fro = q.front();
                    cout << fro.first << ":" << fro.second<< "\n";
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int ny = fro.first + dy[k];
                        int nx = fro.second + dx[k];
                        if(ny < N && ny > -1 && nx < N && nx > -1 && arr[ny][nx] && !vis[ny][nx]){
                            q.push({ny, nx});
                            vis[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }

    return 0; 
}