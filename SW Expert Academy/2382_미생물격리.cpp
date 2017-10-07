//
//  2382_미생물격리.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 7..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
    int x;
    int y;
    int num;
    int dir;
}Node;

priority_queue<Node> q;

bool operator < (Node a, Node b){
    return a.num < b.num;
}

int BFS(int n, int m, int k){
    
    for(int s=0;s<m;s++){
        
        //q에서 pop 해서 방향만큼 1씩 움직인후 다시 push
        priority_queue<Node> q1;
        
        while(!q.empty()){
            int x = q.top().x;
            int y = q.top().y;
            int num = q.top().num;
            int dir = q.top().dir;
            q.pop();
            
            if(dir==1)x-=1;
            if(dir==2)x+=1;
            if(dir==3)y-=1;
            if(dir==4)y+=1;
            
            if(x==0||y==0||x==n-1||y==n-1){
                num = num/2;
                if(dir%2==0) dir--;
                else dir++;
            }
            
            q1.push({x,y,num,dir});
        }
        
        //초기화
        Node arr[100][100];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j].num = 0;
            }
        }
        
        while(!q1.empty()){
            int x = q1.top().x;
            int y = q1.top().y;
            int num = q1.top().num;
            int dir = q1.top().dir;
            q1.pop();
            
            if(arr[x][y].num == 0){
                arr[x][y].x = x;
                arr[x][y].y = y;
                arr[x][y].dir = dir;
                arr[x][y].num = num;
            }
            else{
           
                if(arr[x][y].num > num){
                    arr[x][y].num += num;
                }
                else{
                    arr[x][y].num += num;
                    arr[x][y].dir = dir;
                }
                
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j].num != 0){
                    q.push(arr[i][j]);
                }
            }
        }
    }
    
    int ans = 0;
    
    while(!q.empty()){
        ans += q.top().num;
        q.pop();
    }
    
    return ans;
}

void solve(int tc){
    
    int n,m,k;
    
    cin>>n>>m>>k;
    Node a;
    for(int i=0;i<k;i++){
        cin>>a.x>>a.y>>a.num>>a.dir;
        q.push(a);
    }
    
    cout<<'#'<<tc<<' '<<BFS(n,m,k)<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++) solve(i);
}
