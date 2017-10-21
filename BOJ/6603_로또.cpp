//
//  6603_로또.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 21..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int arr[15];
vector<int> v;
void dfs(int cur , int n, int cnt){
    if(v.size()==6){
        for(int i=0;i<6;i++) cout<<v[i]<<' ';
        cout<<'\n';
        return;
    }
    
    for(int i=cur;i<n;i++){
        v.push_back(arr[i]);
        dfs(i+1,n,cnt+1);
        v.erase(v.begin() + v.size() - 1);
    }
}

void solve(int n){
    
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    dfs(0,n,0);
}

int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0) break;
        else solve(n);
        cout<<'\n';
    }
}
