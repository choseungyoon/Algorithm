//
//  2805_농작물수확하기.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 4..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <stdio.h>

int ans;
int arr[50][50];

void solve(int tc){
    ans = 0;
    
    int n;
    scanf("%d", &n);
    
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    
    int s = n/2;
    int t = n/2;
    for(int i=0;i<n;i++){
        
        for(int j=s;j<=t;j++){
            ans += arr[i][j];
        }
        
        if(i<n/2){
            s--,t++;
        }
        else{
            s++,t--;
        }
        
    }
    
    printf("#%d %d\n",tc,ans);
    
}

int main(){
    int tc;
    scanf("%d", &tc);
    
    for(int i=1;i<=tc;i++) solve(i);
}
