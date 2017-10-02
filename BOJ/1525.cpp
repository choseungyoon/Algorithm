//
//  1525.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 9. 25..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
#include <set>
using namespace std;

int arr[3][3];

typedef struct Node{
    int sum;
    int cnt;
}Node;

int dir[4][2] = {
    {1,0}, {0,1}, {-1,0}, {0,-1}
};
set<int> visit;

int BFS(int idx){
    
    queue<Node> q;
    q.push({idx,0});
    int temp[3][3];
    visit.insert(idx);
    
    while(!q.empty()){
        int cur = q.front().sum;
        int cnt = q.front().cnt;
        q.pop();
        
        if(cur == 123456780){
            return cnt;
        }
        int x,y;
        
        for(int i=2;i>=0;i--){
            for(int j=2;j>=0;j--){
                temp[i][j] = cur%10;
                if(temp[i][j] == 0){
                    x = i, y = j;
                }
                cur /= 10;
            }
        }
        
        for(int k=0;k<4;k++){
            int tempX = x + dir[k][0];
            int tempY = y + dir[k][1];
            
            if(tempX<0|| tempX>2 || tempY<0 || tempY>2) continue;
            
            
            //swap
            int t = temp[x][y];
            temp[x][y] = temp[tempX][tempY];
            temp[tempX][tempY] = t;
            
            int sum = 0;
            int digit = 100000000;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    sum += digit*temp[i][j];
                    digit /= 10;
                }
            }
            
            if (visit.find(sum) == visit.end()) {
                visit.insert(sum);
                q.push({sum,cnt+1});
            }
            
            //swap
            t = temp[x][y];
            temp[x][y] = temp[tempX][tempY];
            temp[tempX][tempY] = t;
        }
    }
    
    return -1;
}

int main(){
    int sum = 0;
    int digit = 100000000;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
            sum += digit*arr[i][j];
            digit /= 10;
        }
    }
    
    cout<<BFS(sum)<<endl;
}

