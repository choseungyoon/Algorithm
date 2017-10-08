//
//  1219_길찾기.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 8..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int visited[100];
int arr[100][100];

int dfs(int idx){
    
    if(idx == 99){
        return 1;
    }
    
    for(int i=1;i<100;i++){
        if(arr[idx][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            int flag = dfs(i);
            visited[i] = 0;
            
            if(flag == 1){
                return 1;
            }
        }
    }
    
    return 0;
}

void solve(){
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            arr[i][j] = 0;
        }
    }
    int tc,n;
    cin>>tc>>n;
    
    int from, to;
    
    for(int i=0;i<n;i++){
        cin>>from>>to;
        arr[from][to] = 1;
    }
    visited[0] = 1;
    for(int i=1;i<100;i++){

        if(arr[0][i] == 1){
            visited[i] = 1;
            int flag = dfs(i);
            visited[i] = 0;
            
            if(flag == 1){
                cout<<'#'<<tc<<' '<<1<<'\n';
                return;
            }
        }
    }
    
    cout<<'#'<<tc<<' '<<0<<'\n';
}

int main(){
    for(int i=1;i<=10;i++) solve();
}
