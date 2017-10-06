//
//  1208_Flatten.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 7..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(int tc){
    int n;
    vector<int> v;
    cin>>n;
    int k;
    for(int i=0;i<11;i++){
        cin>>k;
        v.push_back(k);
    }
    
    for(int i=0;i<n;i++){
        sort(v.begin(),v.end());
        if(v[10] - v[0] <= 1){
            break;
        }
        v[10]--;
        v[0]++;
    }
    sort(v.begin(),v.end());
    cout<<'#'<<tc<<' ';
    cout<<v[10]-v[0]<<'\n';
    v.clear();
    
}

int main(){
    for(int i=1;i<=10;i++) solve(i);
}
