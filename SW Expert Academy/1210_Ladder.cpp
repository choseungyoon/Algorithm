//
//  1210_Ladder.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 7..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[101][101];
int ans;
void go(int x, int y, int flag, int first){
    
    if(x==99){
        if(arr[x][y] == 2){
            ans = first;
        }
        
        return;
        
    }
    //flag ==1 아래로 내려가고 있음
    
    if(flag == 1){
        // 왼쪽 or 오른쪽 통로가 있으면 방향 바꿈
        if(y-1>=0 && arr[x][y-1] == 1){
            go(x,y-1,2,first);
        }
        else if(y+1<100 && arr[x][y+1] == 1){
            go(x,y+1,3,first);
        }
        else{
            go(x+1,y,1,first);
        }
    }
    else if(flag==2){
        //flag == 2 왼쪽으로 가고 있음
        //아래로 갈수 있으면 감
        
        if(x+1 < 100 && arr[x+1][y] == 1){
            go(x+1,y,1,first);
        }
        else{
            go(x,y-1,2,first);
        }
    }
    else if(flag==3){
        //flag == 3 오른쪽으로 가고 있음
        //아래로 갈수 있으면 감
        
        if(x+1 < 100 && arr[x+1][y] == 1){
            go(x+1,y,1,first);
        }
        else{
            go(x,y+1,3,first);
        }
    }
    
    return;
}

void solve(){
    int tc;
    
   ans = 0;
    
    cin>>tc;
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cin>>arr[i][j];
            
        }
    }
    
    for(int j=0;j<100;j++){
        if(arr[0][j] == 1){
            go(1,j,1,j);
            if(ans != 0){
                break;
            }
        }
    }
    
    cout<<'#'<<tc<<' '<<ans<<'\n';
}

int main(){
    for(int i=1;i<=10;i++) solve();
}
