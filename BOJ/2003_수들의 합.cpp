//
//  2003_수들의 합.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 7..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[10001];

int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
    int s = 0;
    int e = 0;
    int sum = arr[e];
    int ans = 0;
    while(s<n || e<n){
    
        if(sum>=m){
            if(sum==m){
                ans++;
            }
            sum -= arr[s];
            s++;
        }
        else{
            e++;
            sum+=arr[e];
        }
    }
    
    cout<<ans<<endl;
}
