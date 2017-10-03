//
//  1222_계산기.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 3..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

void solve(int tc){
    int n;
    string str;
    cin>>n>>str;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(str[i]=='+') continue;
        
        ans += str[i]-'0';
    }
    cout<<'#'<<tc<<' ';
    cout<<ans<<'\n';
}

int main(){
    
    for(int i=1;i<=10;i++) solve(i);
}
