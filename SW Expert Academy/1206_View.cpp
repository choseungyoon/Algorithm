//
//  1206_View.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 7..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <stdio.h>

int arr[1002][1002];

void solve(int tc){
    
    int n;
    
    for(int i=0;i<1000;i++){

        for(int j=0;j<1000;j++){
            arr[i][j] = 0;
        }
    }
    
    scanf("%d", &n);
    int m;
    for(int i=0;i<n;i++){
        scanf("%d", &m);
        for(int j=0;j<m;j++){
            arr[i][j] = 1;
        }
    }
    
    int ans = 0;
    
    for(int i=0;i<n;i++){
        int j=0;
        while(arr[i][j]>0){
         
            if(arr[i-2][j]==0 && arr[i-1][j]==0 && arr[i+1][j]==0 && arr[i+2][j]==0){
                ans++;
            }
       
            j++;
        }
    }
    
    printf("#%d %d\n",tc,ans);
}

int main(){
    for(int i=1;i<=10;i++) solve(i);
}
