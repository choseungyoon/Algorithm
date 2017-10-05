//
//  2583_영역구하기.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 5..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node{
    int x;
    int y;
}Node;

int arr[120][120];
int visited[120][120];

int dir[4][2] = {
    {1,0}, {0,1}, {-1,0} , {0,-1}
};

int go(int x, int y, int m, int n){
    
    queue<Node> q;
    q.push({x,y});
    int result = 1;
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        q.pop();
        
        for(int k=0;k<4;k++){
            int tempX = x + dir[k][0];
            int tempY = y + dir[k][1];
            
            if(tempX < 0 || tempX>=n || tempY < 0 || tempY>=m) continue;
            
            if(arr[tempX][tempY] == 0 && visited[tempX][tempY] == 0){
                visited[tempX][tempY] = 1;
                result++;
                q.push({tempX,tempY});
            }
        }
    }
    
    return result;
}

int main(){
    int n,m,k;
    
    //INPUT
    cin>>n>>m>>k;
    
    int x1,y1,x2,y2;
    
    for(int i=0;i<k;i++){
        cin>>y1>>x1>>y2>>x2;
        for(int a = x1;a<x2;a++){
            for(int b=y1;b<y2;b++){
                arr[a][b] = 1;
            }
        }
    }
    //INPUT DONE
    
    //Start
    
    int ans = 0;
    vector<int> v;
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0 && visited[i][j] == 0){
                visited[i][j] = 1;
                ans++;
                int wide = go(i,j,m,n);
                v.push_back(wide);
            }
        }
    }

    sort(v.begin(),v.end());

    cout<<ans<<'\n';
    for(int i=0;i<ans;i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
}
