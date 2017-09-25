//
//  1220_Magnetic.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 9. 26..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[100][100];

int main(){
    
    for(int t=0;t<10;t++){
        int n;
        int ans = 0;
        cin>>n;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        
        // 1 -> 아래로
        // 2 -> 위로
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] == 1){
                    //아래로
                    for(int a = i+1;a<n;a++){
                        if(arr[a][j] == 2){
                            ans++;
                            arr[a][j] = 3;
                            if(a-1>=0) arr[a-1][j] = 3;
                            break;
                        }
                        else{
                            arr[a][j] = 1;
                            if(a-1>=0) arr[a-1][j] = 0;
                        }
                    }
                    
                }
                else if(arr[i][j] == 2){
                    //위로
                    for(int a = i-1;a>=0;a--){
                        if(arr[a][j] == 1){
                            ans++;
                            arr[a][j] = 3;
                            if(a+1<n) arr[a+1][j] = 3;
                            break;
                        }
                        else{
                            arr[a][j] = 2;
                            if(a+1<n) arr[a+1][j] = 0;
                        }
                    }
                }
            }
        }
        
        cout<<ans<<endl;
    }
}
