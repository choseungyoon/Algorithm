//
//  14710_고장난시계.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 11. 4..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int a,b;
    
    cin>>a>>b;
    int i= 0 , j = 0;

    while(i<360){
        if(i== a*12 && j==b*12){
            cout<<'O'<<endl;
            return 0;
        }
        
        j+=12;
        i+=1;
        if(j >= 360*12) j = 0;
        if(i >= 360*12) break;
    }
    
    cout<<'X'<<endl;
}
