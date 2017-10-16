//
//  1860_진기의최고급붕어빵.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 16..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int bread[11113];
int cus[11113];

void solve(int tc){
    int n,m,k;
    
    cin>>n>>m>>k;
    int t;
    int last=0;
    for(int i=0;i<11112;i++){
        bread[i]= 0 , cus[i] = 0;
    }
    
    for(int i=0;i<n;i++){
        cin>>t;
        cus[t] = 1;
        if(t>last) last = t;
    }
    
    for(int i=0;i<=last;i++){
        
        //빵 만들기
        if(i!= 0  && i%m==0){
            bread[i] = bread[i-1] + k;
        }
        else{
            if(i==0) bread[i] = 0;
            else bread[i] = bread[i-1];
        }
        
        //손님이 왔을 때 붕어빵 몇개 있는지 확인
        if(cus[i] == 1 ){
            if(bread[i] < 1){
                cout<<'#'<<tc<<" Impossible\n";
                return;
            }
            else{
                bread[i] -=1;
            }
        }
        
    }
    
    cout<<'#'<<tc<<" Possible\n";
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
