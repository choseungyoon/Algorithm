//
//  11811_데스스타.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 4..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int ans[1001];

int main(){
    int n;
    int a;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            
            ans[i] = ans[i] | a;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}
