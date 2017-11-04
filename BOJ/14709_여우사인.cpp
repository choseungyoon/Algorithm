//
//  14709_여우사인.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 11. 4..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int fox[3] = {0,};
    
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if((a==1 && b==3) || (a==3 && b==1)) fox[0] = 1;
        else if((a==4 && b==3) || (a==3 && b==4)) fox[1] = 1;
        else if((a==1 && b==4) || (a==4 && b==1)) fox[2] = 1;
        else{
            cout<<"Woof-meow-tweet-squeek\n";
            return 0;
        }
    }
    
    if(fox[0] ==1 && fox[1] == 1 && fox[2] == 1)
        cout<<"Wa-pa-pa-pa-pa-pa-pow!\n";
    else
        cout<<"Woof-meow-tweet-squeek\n";
}
