//
//  2117_홈방범서비스.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 19..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int arr[30][30];

typedef struct Node{
    int x;
    int y;
}Node;

int BFS(int k, int x, int y, int n){
    int ans = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            int temp = 0;
            int r = 0;
            for(int s = i - (2*k-1)/2 ; s <= i + (2*k-1)/2 ; s++){
                
                if(s<i){
                    for(int t = j-r ; t <= j + r ; t++){
                        if(s>=0 && s<n && t>=0 && t<n){
                            if(arr[s][t] == 1) temp++;
                        }
                        
                    }
                    r++;
                }
                else{
                    for(int t = j-r ; t <= j + r ; t++){
                        if(s>=0 && s<n && t>=0 && t<n){
                           if(arr[s][t] == 1) temp++;
                        }
                    }
                    r--;
                }
            }
            
            if(ans < temp) ans = temp;
            
        }
    }
    
    return ans;
}

void solve(int tc){
    
    int n,m;
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    int ans = 0;
    
    for(int k=1;k <=n+1 ; k++){
        int tmp = BFS(k,0,0,n);
        if(tmp*m - k*k - (k-1)*(k-1) >= 0 )
            if(ans < tmp) ans = tmp;
    }
    
    cout<<'#'<<tc<<' '<<ans<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
