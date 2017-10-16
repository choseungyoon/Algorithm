//
//  1952_수영장.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 12..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int money[4];
int month[20];
int ans;

void go(int sum,int cur){
    
    if(cur>=12){
        if(ans > sum) ans = sum;
        return;
    }
    go(sum+money[0]*month[cur], cur+1);
    go(sum+money[1], cur+1);
    go(sum+money[2], cur+3);
}

void solve(int tc){
    
    for(int i=0;i<4;i++) cin>>money[i];
    for(int i=0;i<12;i++)cin>>month[i];
    
    ans = 10000000;
    go(0,0);
    
    if(ans > money[3]) ans = money[3];
    
    cout<<'#'<<tc<<' '<<ans<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++) solve(i);
}
