//
//  2115_벌꿀채취.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 2..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[12][12];
int visited[12][12];
int ans = 0;

void GO(int x, int y,int n,int m ,int c){
    
    int a = 0;
    
    //첫번째 벌꿀통
    vector<int> v;
    for(int j=y ; j<y+m;j++){
        v.push_back(arr[x][j]);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(), v.end());
    
    for(int i=0 ; i <m ; i++){
        int tmp = 0;
        int t_a = 0;
        for(int j=i;j<m;j++){
            tmp += v[j];
            if(tmp <= c){
                t_a += v[j]*v[j];
            }
            else{
                tmp -= v[j];
            }
        }
        if(t_a > a) a = t_a;
    }
    v.clear();
    //두번째 벌꿀통
    
    for(int i = x ; i<n;i++){
        for(int j = 0 ; j<n;j++){
            
            if(i==x){
                if(j<=y+m-1) continue;
            }
            
            if(j+m-1<n){
                vector<int> v;
                
                for(int k=j ; k<j+m;k++){
                    v.push_back(arr[i][k]);
                }
                sort(v.begin(),v.end());
                reverse(v.begin(), v.end());
                
                int b = 0;
                for(int t=0 ; t <m ; t++){
                    int tmp = 0;
                    
                    int t_b = 0;
                    for(int s = t ; s<m;s++){
                        tmp += v[s];
                        if(tmp <= c){
                            t_b += v[s]*v[s];
                        }
                        else{
                            tmp -= v[s];
                        }
                    }
                    
                    if(t_b > b) b = t_b;
                    
                    
                }
                
                if(a+b > ans) ans = a + b;
                v.clear();
                
            }
        }
    }
    
}

void solve(int tc){
    int n,m,c;
    ans = 0;
    cin>>n>>m>>c;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j+m-1<n){
                
                GO(i,j,n,m,c);
            }
            
        }
    }
    
    cout<<'#'<<tc<<' ';
    cout<<ans<<endl;
}

int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)solve(i);
}
