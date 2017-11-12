//
//  Stack_by_array.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 11. 12..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX_SIZE 1000

void Stack_push(int *stack,int val,int *top){
    stack[*top] = val;
    *top += 1;
}

int Stack_pop(int *stack, int *top){
    *top -= 1;
    return stack[*top];
}

int main(){
    
    //Array_stack
    int stack[MAX_SIZE];
    int top = 0;
    
    int n,val;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>val;
        if(top>=MAX_SIZE){
            cout<<"Out of range\n";
            cout<<"Cannot Push anymore\n";
        }
        else{
            //STACK_PUSH
            Stack_push(stack,val,&top);
            cout<<val<<" Push completed\n";
        }
    }
    
    cout"------------------\n"
    
    for(int i=0;i<n;i++){
        // Print current Stack Size
        cout<<"Stack Size is : "<<top<<'\n';
        
        if(top>0){
            int popvalue = Stack_pop(stack,&top);
            cout<<popvalue<<" is removed\n";
        }
    }
    
    return 0;
}
