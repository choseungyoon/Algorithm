//
//  1234_비밀번호.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 18..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

void solve(int tc){
    
    int n;
    string str;
    cin>>n>>str;
    
    
    while(1){
        int len = (int)str.length();
        int end = 0;
        for(int i=0;i<len;i++){
            if(str[i] == str[i+1]){
                end = 1;break;
            }
        }
        if(end==0) break;
        for(int i=0;i<len;i++){
            if(str[i] == str[i+1]){
                str.erase(str.begin()+i);
                str.erase(str.begin()+i);
                i=0;
                len = (int)str.length();
            }
        }
        
        
    }
    cout<<'#'<<tc<<' ';
    
    cout<<str;
    cout<<'\n';
}

int main(){
    for(int i=1;i<=10;i++) solve(i);
}
