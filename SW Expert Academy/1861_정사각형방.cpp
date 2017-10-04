//
//  1861_정사각형방.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 4..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];

typedef struct Node{
    int x;
    int y;
    int cnt;
}Node;

int dir[4][2] = {
    {1,0},{0,1}, {-1,0}, {0,-1}
};


int go(int x, int y, int cur, int n){
    dp[x][y] = cur;
    
    for(int k=0;k<4;k++){
        int tempX = x + dir[k][0];
        int tempY = y + dir[k][1];
        
        if(tempX<0|| tempX>=n||tempY <0 || tempY >=n) continue;
        
        if(dp[tempX][tempY] == 0 && arr[x][y] + 1 == arr[tempX][tempY]){
            int tmp = go(tempX,tempY,cur+1,n);
            dp[x][y] = tmp;
        }
        else if(dp[tempX][tempY] > 0 && arr[x][y] + 1 == arr[tempX][tempY]){
            dp[x][y] = dp[tempX][tempY] + 1;
            
        }
    }
    
    return dp[x][y];
}

void solve(int tc){
    int ans = 0;
    int idx=1000000;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            dp[i][j] = 0;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==0){
                int tmp = go(i,j,1,n);
                if(tmp>ans){
                    ans = tmp;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] == ans){
                if(idx > arr[i][j]){
                    idx = arr[i][j];
                }
            }
        }
    }
    
    cout<<'#'<<tc<<' ';
    cout<<idx<<' '<<ans<<'\n';
    
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
