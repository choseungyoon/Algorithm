//
//  1767_프로세서연결하기.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 21..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef struct Node{
    int x;
    int y;
}Node;
int n;
int dir[4][2] = {
    {0,1} , {1,0} ,{-1,0} , {0,-1}
};

int arr[20][20];
int visited[20][20];
int ans_core;
int ans_line;

vector<Node> v;

int check(int x, int y, int k){
    int len = 0;
    while(1){
        x = x + dir[k][0];
        y = y + dir[k][1];
        
        if(x<0 || x>=n || y < 0 ||  y>=n) break;
        
        if(arr[x][y] == 0 && visited[x][y] == 0){
            len++;
            continue;
        }
        else{
            return 0;
        }
    }
    
    return len;
}

void DFS(int cur, int num,int line, int core_num){
    if(cur == num){
        //max_core check
         //line length check
        if(ans_core < core_num){
            ans_core = core_num;
            ans_line = line;
        }
        else if(ans_core == core_num){
            if(ans_line > line)
                ans_line = line;
        }
       
        return;
    }
    
    for(int i=cur ; i<num;i++){
        for(int k=0;k<4;k++){
            
                //각 방향으로 연결할 수 있는지 체크
                int temp_len = check(v[i].x,v[i].y,k);
                if( temp_len > 0){
                    //갈수있으면
                    //LINE 표시
                    int nex = v[i].x , ney=v[i].y;
                    while(nex>=0  && nex<n && ney >= 0 && ney < n){
                        visited[nex][ney] = 1;
                        nex += dir[k][0] , ney += dir[k][1];
                    }
                    DFS(i+1 , num , line + temp_len, core_num+1);
                
                    //LINE 표시 복귀
                    nex = v[i].x , ney=v[i].y;
                    while(nex>=0  && nex<n && ney >= 0 && ney < n){
                        visited[nex][ney] = 0;
                        nex += dir[k][0] , ney += dir[k][1];
                    }
                }
            
        }
    }
}

void solve(int tc){

    cin>>n;
    ans_core = 0;
    ans_line = 10000000;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                if(i==0 || i==n-1 || j==0 || j==n-1) continue;
                v.push_back({i,j});
                visited[i][j] = 0;
            }
        }
    }
    
    DFS(0, (int)v.size(),0,0);
    
    cout<<'#'<<tc<<' '<<ans_line<<'\n';
    v.clear();
}

int main(){
    int tc;
    cin>>tc;
    for(int i=1 ; i<=tc;i++) solve(i);
}
