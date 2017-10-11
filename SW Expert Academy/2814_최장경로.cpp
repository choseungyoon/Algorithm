//
//  2814_최장경로.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 12..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[20][20];
int visited[20];
int ans;

void go(int cur, int len, int n){
    if(len > ans) ans = len;
    
    for(int i=1;i<=n;i++){
        if(i==cur) continue;
        
        if(arr[cur][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            go(i,len+1,n);
            visited[i] = 0;
        }
    }
}
void solve(int tc){
    
    int n,m;
    cin>>n>>m;
    int x,y;
    ans = 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            arr[i][j] = 0;
        }
    }
    
    for(int i=0;i<=n;i++) visited[i] = 0;
    
    for(int i=0;i<m;i++){
        cin>>x>>y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j] == 1){
                visited[i] = 1;
                visited[j] = 1;
                go(j,2,n);
                visited[i] = 0;
                visited[j] = 0;
            }
        }
    }
    
    cout<<'#'<<tc<<' '<<ans<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
