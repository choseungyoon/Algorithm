//
//  1218_괄호짝짓기.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 8..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;


void solve(int tc){
    int n;
    cin>>n;
    string str;
    cin>>str;
    stack<char> s;
    
    for(int i=0;i<n;i++){
        if(str[i] == '{' || str[i] == '['|| str[i] == '('){
            s.push(str[i]);
        }
        else{
            if(str[i] == '}'){
                if(s.top() == '{'){
                    s.pop();
                }
                else{
                    cout<<'#'<<tc<<' '<<0<<'\n';
                    return;
                }
            }
            else if(str[i] == ']'){
                if(s.top() == '['){
                    s.pop();
                }
                else{
                    cout<<'#'<<tc<<' '<<0<<'\n';
                    return;
                }
            }
            else if(str[i] == ')'){
                if(s.top() == '('){
                    s.pop();
                }
                else{
                    cout<<'#'<<tc<<' '<<0<<'\n';
                    return;
                }
            }
        }
    }
    cout<<'#'<<tc<<' '<<1<<'\n';
}

int main(){
    for(int i=1;i<=10;i++) solve(i);
}
