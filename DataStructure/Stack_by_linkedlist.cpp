//
//  Stack_by_linkedlist.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 11. 12..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//


//
//  Stack_by_linkedlist.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 11. 12..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node *next;
}Node;

Node *head;

int size_stack = 0;

void Stack_push(int val){
    //새로운 노드를 만들고
    Node *newNode = new Node;
    newNode->data = val;
    
    //리스트의 맨 앞(head)에 연결합니다.
    newNode->next = head->next;
    head->next = newNode;
    size_stack++;
}

int Stack_pop(){
    
    
    int popvalue;
    
    if(size_stack<1){
        return -1;
    }
    //temp 배열에 맨앞에 노드의 주소를 저장합니다.
    Node *temp = head->next;
    popvalue = temp->data;
    
    //head를 두번째 노드에 연결시키고
    head->next = temp->next;
    
    //첫번째 노드를 삭제합니다.
    free(temp);
    size_stack--;
    return popvalue;
}

int main(){
    
    //head 초기화
    head = new Node;
    
    int n;
    int val;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>val;
        Stack_push(val);
        cout<<val<<" is added\n";
    }
    
    cout<<"------------------------------\n";
    
    for(int i=0;i<n;i++){
        cout<<"Current stack size is : "<<size_stack<<'\n';
        int popvalue = Stack_pop();
        if(popvalue==-1){
            cout<<"Stack is empty\n";
        }
        else{
            cout<<popvalue<<" is removed\n";
        }
    }
    
    return 0;
}
