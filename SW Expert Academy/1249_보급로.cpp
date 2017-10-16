//
//  1249_보급로.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 16..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = {
    {0,1}, {1,0} ,{-1,0}, {0,-1}
};

typedef struct Node{
    int val;
    int x;
    int y;
    int cur;
}Node;

Node arr[100][100];
int visited[100][100];

void BFS(int n){
    
    queue<Node> q;
    q.push({0,0,0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int k=0;k<4;k++){
            int tempX = x + dir[k][0];
            int tempY = y + dir[k][1];
            
            if(tempX<0 || tempX>=n || tempY < 0 || tempY >=n) continue;
            
            if(visited[tempX][tempY] == 0){
                visited[tempX][tempY] = 1;
                arr[tempX][tempY].cur = arr[x][y].cur + arr[tempX][tempY].val;
                q.push({arr[tempX][tempY].val,tempX,tempY,arr[tempX][tempY].cur});
            }
            else{
                if(arr[tempX][tempY].cur > arr[x][y].cur + arr[tempX][tempY].val){
                    arr[tempX][tempY].cur = arr[x][y].cur + arr[tempX][tempY].val;
                    q.push({arr[tempX][tempY].val,tempX,tempY,arr[tempX][tempY].cur});
                }
            }
        }
    }
}

void solve(int tc){
    
    int n;
    cin>>n;
    string t;
    for(int i=0;i<n;i++){
        cin>>t;
        for(int j=0;j<n;j++){
            arr[i][j].val = t[j]-'0';
            arr[i][j].x = i;
            arr[i][j].y = j;
            arr[i][j].cur = 0;
            visited[i][j] = 0;
        }
    }
    
    BFS(n);
    cout<<'#'<<tc<<' '<<arr[n-1][n-1].cur<<'\n';
    
}

int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++) solve(i);
}
