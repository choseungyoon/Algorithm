//
//  1245_균형점.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 8..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Node{
    double x;
    double m;
}Node;

Node mat[12];

int cmp(Node a, Node b){
    return a.x<b.x;
}

void Bsearch(int idx,int n){
    
    double left = mat[idx].x;
    double right = mat[idx+1].x;
    
    while(1){
        double mid = (left+right)/2.0;
        double LeftF = 0;
        double RightF = 0;
        
        for(int i=0;i<=idx;i++){
            LeftF += mat[i].m / ((mat[i].x-mid)*(mat[i].x-mid));
        }
        
        for(int i=idx+1;i<n;i++){
            RightF += mat[i].m / ((mat[i].x-mid)*(mat[i].x-mid));
        }
        
        if(right - left < 1e-9){
            cout << fixed;
            cout.precision(10);
            
            cout<<mid<<' ';
            break;
        }
        
        if(LeftF<RightF) right = mid;
        else left = mid;
    }
}

void solve(int tc){
    
    int n;
    //INPUT
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>mat[i].x;
    }
    
    for(int i=0;i<n;i++){
        cin>>mat[i].m;
    }
    
    //sort
    sort(mat, mat+n,cmp);
    
    cout<<'#'<<tc<<' ';
    
    for(int i=0;i<n-1;i++){
        Bsearch(i,n);
    }
    cout<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++){
        solve(i);
    }
}
