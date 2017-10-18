//
//  1238_contact.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 18..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[151][151];
int visited[151];

int BFS(int n, int start){
    
    queue<int> q;
    visited[start] = 1;
    for(int i=1;i<=100;i++){
        if(arr[start][i] == 1){
            q.push(i);
            visited[i] = 1 ;
        }
    }
    
    vector<int> last;
    while(!q.empty()){

        int len = (int)q.size();
        last.clear();
        for(int i=0;i<len;i++){
            int cur = q.front();
            last.push_back(cur);
            q.pop();
            
            for(int j=1;j<=100;j++){
                
                if(arr[cur][j] == 1 && visited[j] == 0){
                    visited[j] = 1;
                    q.push(j);
                }
            }
            
        }
    
    }
    sort(last.begin(),last.end());
    reverse(last.begin(),last.end());
    return last.front();
}

void solve(int tc){
    
    int n,s;
    cin>>n>>s;
    int from, to;
    
    for(int i=1 ; i<=100;i++){
        visited[i] = 0;
        for(int j=1;j<=100;j++){
            arr[i][j] = 0;
        }
    }
    
    for(int i=0;i<n/2;i++){
        cin>>from>>to;
        arr[from][to] = 1;
    }
    
    
    cout<<'#'<<tc<<' '<< BFS(n,s)<<'\n';
}

int main(){
    for(int i=1;i<=10;i++) solve(i);
}
