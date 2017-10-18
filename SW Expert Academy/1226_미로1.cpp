//
//  1226_미로1.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 18..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
char arr[111][111];
int visited[111][111];

typedef struct Node{
    int x,y;
}Node;

int dir[4][2] = {
    {0,1}, {1,0}, {-1,0}, {0,-1}
};

int BFS(){
    
    queue<Node> q;
    q.push({1,1});
    
    visited[1][1] = 1;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int k=0;k<4;k++){
            int tempX = x + dir[k][0];
            int tempY = y + dir[k][1];
            
            if(tempX<0 || tempX>=100 || tempY<0 || tempY >=100) continue;
            
            if(visited[tempX][tempY] == 0 && arr[tempX][tempY] == '0'){
                visited[tempX][tempY] = 1;
                q.push({tempX,tempY});
            }
            else if(arr[tempX][tempY] == '3') return 1;
        }
    }
    
    return 0;
}
void solve(int tc){
    int n;
    cin>>n;
    for(int i=0;i<100;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            visited[i][j] = 0;
        }
    }
    cout<<'#'<<n<<' ';
    if(BFS()==1) cout<<1<<endl;
    else cout<<0<<endl;
}

int main(){
    for(int i=1;i<=10;i++)solve(i);
}
