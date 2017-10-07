//
//  1806_부분합.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 7..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[100020];

int main(){
    int n,m;
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int s = 0;
    int e = 0;
    int sum = arr[e];
    int ans = 1000000;
    
    while(s<n && e<n){
        
        if(sum>=m){
            if(e-s+1 < ans){
                ans = e-s+1;
            }
            
            sum-=arr[s];
            s++;
        }
        else{
            e++;
            sum += arr[e];
        }
    }
    
    if(ans == 1000000) ans = 0;
    
    cout<<ans<<endl;
}
