//
//  1247_최적경로.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 4..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef struct Node{
    int x,y;
}Node;
Node arr[12];
int ans;
int visited[12];

int dis(int x1, int y1, int x2, int y2){
    int a = x1-x2;
    if(a<0) a*=(-1);
    int b = y1 - y2;
    if(b<0) b*= (-1);
    
    return a+b;
}

void go(int to_x, int to_y, int idx,int cur,int n,int sum){
    if(cur == n){
        int tmp = sum + dis(arr[idx].x,arr[idx].y,to_x,to_y);
        if(tmp < ans) ans = tmp;
    }
    
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            go(to_x,to_y,i,cur+1,n,sum+dis(arr[idx].x,arr[idx].y,arr[i].x,arr[i].y));
            visited[i] = 0;
        }
    }
}

void solve(int tc){
    ans = 100000;
    int x1,y1,x2,y2;
    int n;
    cin>>n;
    cin>>x1>>y1>>x2>>y2;
    for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
    
    for(int i=0;i<n;i++){
        visited[i] = 1;
        go(x2,y2,i,1,n,dis(x1,y1,arr[i].x,arr[i].y));
        visited[i] = 0;
    }
    
    cout<<'#'<<tc<<' ';
    cout<<ans<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
