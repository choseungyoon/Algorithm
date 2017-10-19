//
//  9376_탈옥.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 19..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

char arr[101][101];
char save[101][101];
int visited[101][101];

int n,m;

typedef struct Node{
    int x;
    int y;
    int num_open;
    char before;
}Node;

typedef struct Person{
    int x;
    int y;
}Person;

Person p[2];

int dir[4][2] = {
    {0,1} , {1,0}, {-1,0} , {0,-1}
};

int BFS(int i, int j, int open,int flag){
    queue<Node> q;
    q.push({i,j,open,arr[i][j]});
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 0;
        }
    }
    visited[i][j] = 1;
    
    
    
    
    return 0;
}

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = save[i][j];
        }
    }
}

void solve(){

    cin>>n>>m;
    int flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            save[i][j] = arr[i][j];
            if(arr[i][j] == '$'){
                if(flag==0){
                    p[0].x = i, p[0].y=j;
                    flag = 1;
                }
                else{
                    p[1].x = i, p[1].y=j;
                }
            }
        }
    }
    
    int ans = 10000000;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( i==0 || i == n-1 || j==0 || j==m-1){
                if(arr[i][j] == '.'){
                    int tmp = BFS(i,j,0,0);
                    if(tmp < ans) ans = tmp;
                }
                else if(arr[i][j] == '#'){
                    int tmp = BFS(i,j,1,0);
                    if(tmp < ans) ans = tmp;
                }
            }
            reset();
        }
    }
    
    printf("%d\n", ans);
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=0;i<tc;i++) solve();
}
