//
//  2112_보호필름.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 19..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[25][25];

int check(int d, int w,int k){
    
    for(int j=0;j<w;j++){
        int flag = 0;
        for(int i=0;i<d;i++){
            if(k==1){
                flag = 1;
                break;
            }
            if(i+1 < d && arr[i][j] == arr[i+1][j]){
                int cur = 2;
                if(k==2){
                    flag = 1;
                    break;
                }
                
                for(int s = i+2;s<d;s++){
                    if(arr[i][j] == arr[s][j]){
                        cur++;
                        if(k <= cur){
                            flag = 1;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            
            if(flag == 1) break;
            
        }
        if(flag == 0) return 0;
    }
    
    return 1;
}

int setgroup(int cur, int t, int d, int w,int choose,int k){
    
    if(cur == t){
        //check
        if(check(d,w,k) == 1){
                return t;
            }
        }
    else{
        int temp[20];
        //A로 변경
        
        for(int i=choose;i<d;i++){
            for(int j=0;j<w;j++){
                temp[j] = arr[i][j];
                arr[i][j] = 0;
            }

            int tmp = setgroup(cur+1, t, d,w, i+1 ,k);
            if(tmp >= 0 ) return tmp;
            else{
                for(int j=0;j<w;j++) arr[i][j] = temp[j];
            }
        }
        
        //B로 변경
        for(int i=choose;i<d;i++){
            for(int j=0;j<w;j++){
                temp[j] = arr[i][j];
                arr[i][j] = 1;
            }

            int tmp = setgroup(cur+1, t, d,w, i+1 ,k);
            if(tmp >= 0 ) return tmp;
            else{
                for(int j=0;j<w;j++) arr[i][j] = temp[j];
            }
        }
    }
    return -1;
    
}



void solve(int tc){
    int d,w,k;
    
    cin>>d>>w>>k;
    
    for(int i=0;i<d;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }
    int ans = -1;
    for(int t=0;t<=d;t++){
        //t개씩 선택
        ans = setgroup(0,t,d,w,0,k);
        if(ans >= 0) {
            break;
        }
    }
    
    cout<<'#'<<tc<<' '<<ans<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
