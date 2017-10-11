//
//  1244_최대상금.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 3..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

int ans;
bool visited[1000000];

int check(int *arr, int s){
    int sum = 0;
    for(int i=0;i<s;i++){
        sum *=10;
        sum += arr[i];
    }
    return sum;
}

void change(int *arr , int cur, int m,int s,int from){
    if(cur == m){
        int tmp = check(arr,s);
        if(ans < tmp) ans = tmp;
        return;
    }
    
    int curnum = check(arr,s);
    if(visited[curnum]) return;
    visited[curnum] = true;
    
    for(int i=from;i<s;i++){
        for(int j=i+1;j<s;j++){
            if(i==j) continue;
            
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            
            change(arr, cur+1, m, s,i);
            
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
}

void solve(int tc){
    
    int n,m;
    cin>>n>>m;
    ans = 0;
    int tmp[6] = {0,};
    int arr[6] = {0,};
    memset(visited, false, sizeof(visited));
    int s=0;
    while(n>=10){
        tmp[s++] = n%10;
        n/=10;
    }
    tmp[s++] = n;
    
    for(int i=0;i<s;i++){
        arr[i] = tmp[s-1-i];
    }
    
    change(arr,0,m,s,0);
    cout<<'#'<<tc<<' ';
    cout<<ans<<'\n';
    
}

int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++) solve(i);
}
