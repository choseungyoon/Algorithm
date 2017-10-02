//
//  2819_격자판의숫자이어붙이기.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 2..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <string.h>
using namespace std;

typedef struct Node{
    int num;
    int x;
    int y;
    int cnt;
}Node;

int arr[4][4];
int ans;
set<int> visit;

int dir[4][2] = {
    {1,0} , {0,1} , {-1,0} , {0,-1}
};

void go(int x, int y, int cur){
    
    
    queue<Node> q;
    q.push({arr[x][y],x,y,1});
    
    while(!q.empty()){
        int cur = q.front().num;
        x = q.front().x;
        y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        
        for(int k=0;k<4;k++){
            int tempX = x + dir[k][0];
            int tempY = y + dir[k][1];
            
            if(tempX < 0 || tempX >= 4 || tempY < 0 || tempY >=4) continue;
            
            int temp_cur = cur*10 + arr[tempX][tempY];
            
            if(cnt+1 == 7){
                if(visit.end() == visit.find(temp_cur)){
                    ans++;
                    visit.insert(temp_cur);
                }
            }
            else{
                q.push({temp_cur,tempX,tempY,cnt+1});
            }
        }
    }
}

void solve(int tc){
    ans = 0;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            go(i,j,1);
        }
    }
    
    
    cout<<'#'<<tc<<' ';
    cout<<ans<<endl;
    
    visit.clear();
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i = 1 ; i<=tc ; i++) solve(i);
}
