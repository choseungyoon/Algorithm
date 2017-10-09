//
//  1949_등산로조성.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 10..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int arr[10][10];
int ans;

typedef struct Node{
    int x;
    int y;
    int cnt;
}Node;

int dir[4][2] = {
    {1,0}, {0,1},{-1,0}, {0,-1}
};

void bfs(int x, int y, int n){
    queue<Node> q;

    q.push({x,y,1});
    
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        
        if(ans < cnt){
            ans = cnt;
        }
        
        for(int k=0;k<4;k++){
            int tempX = x +dir[k][0];
            int tempY = y +dir[k][1];
            
            if(tempX<0|| tempX>=n||tempY <0|| tempY>=n) continue;
            
            if(arr[tempX][tempY] < arr[x][y] ){
                q.push({tempX,tempY,cnt+1});
            }
        }
        
    }
}

void go(int n,int max){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == max){
                bfs(i,j,n);
            }
        }
    }
}



void solve(int tc){
    
    int n,k;
    ans = 0;
    int max = 0;
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(max < arr[i][j]) max = arr[i][j];
        }
    }
    
    for(int s=0;s<=k;s++){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] -= s;
                go(n,max);
                arr[i][j] += s;
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
