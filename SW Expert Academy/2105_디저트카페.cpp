//
//  2105_디저트카페.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 2..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

int arr[22][22];
int ans;

int check(int x, int y,int n){
    if(x<0||x>=n||y<0||y>=n) return 0;
    
    return 1;
}

int go(int x,int y,int a, int b,int n){
    int cnt = 1;
    int visited[100] = {0,};
    visited[arr[x][y]] = 1;
    
    //왼쪽아래로 go
    for(int i=0;i<a;i++){
        x+=1;
        y-=1;
        //범위 확인
        if(check(x,y,n)==1){
            if(visited[arr[x][y]] == 0){
                visited[arr[x][y]] = 1;
                cnt++;
            }
            else{
                return 0;
            }
        }
        else{
            //벗어나면 그냥 끝
            return 0;
        }
    }
    
    //오른쪽 아래로 go
    for(int i=0;i<b;i++){
        x+=1;
        y+=1;
        //범위 확인
        if(check(x,y,n)==1){
            if(visited[arr[x][y]] == 0){
                visited[arr[x][y]] = 1;
                cnt++;
            }
            else{
                return 0;
            }
        }
        else{
            //벗어나면 그냥 끝
            return 0;
        }
    }
    
    
    //오른쪽 위로 go
    for(int i=0;i<a;i++){
        x-=1;
        y+=1;
        //범위 확인
        if(check(x,y,n)==1){
            if(visited[arr[x][y]] == 0){
                visited[arr[x][y]] = 1;
                cnt++;
            }
            else{
                return 0;
            }
        }
        else{
            //벗어나면 그냥 끝
            return 0;
        }
    }
    
    //왼쪽 위로go
    for(int i=0;i<b-1;i++){
        x-=1;
        y-=1;
        //범위 확인
        if(check(x,y,n)==1){
            if(visited[arr[x][y]] == 0){
                visited[arr[x][y]] = 1;
                cnt++;
            }
            else{
                return 0;
            }
        }
        else{
            //벗어나면 그냥 끝
            return 0;
        }
    }
    
    return cnt;
}

void solve(int tc){
    ans = -1;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    
    for(int s=1;s<n;s++){
        for(int t=1;t<n;t++){
            
            if(s+t<n){
                int flag = 0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        flag = go(i,j,s,t,n);
                        if(flag > 0 ){
                            if(ans < flag) ans = flag;
                            break;
                        }
                    }
                    if(flag>0)break;
                }
            }
            
        }
    }
    cout<<'#'<<tc<<' ';
    cout<<ans<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
