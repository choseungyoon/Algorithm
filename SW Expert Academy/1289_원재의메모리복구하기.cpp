//
//  1289_원재의메모리복구하기.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 12..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

void solve(int tc){
    
    int ans = 0;

    string str;
    cin>>str;
 
    char cur = '0';
    int len = (int)str.length();
    
    for(int i=0;i<len;i++){
        if(str[i] == cur){
            continue;
        }
        else{
            ans++;
            if(cur=='0') cur = '1';
            else cur = '0';
        }
    }
    
    cout<<'#'<<tc<<' '<<ans<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
