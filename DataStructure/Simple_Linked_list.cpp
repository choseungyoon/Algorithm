//
//  Simple_Linked_list.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 11. 9..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node *next;
}Node;


Node *head;
Node *tail;

void init(){
    head = new Node;
    tail = new Node;
    
    head->next = NULL;
    tail->next = NULL;
}

void Addnode(int data){
    
    //추가할 노드 만들기
    Node *NewNode = new Node;
    
    NewNode->data = data;
    NewNode->next = NULL;
    
    //노드가 하나도 없으면 head에 연결하기
    if(head->next == NULL){
        head->next = NewNode;
    }
    else{
        
        //새로 추가되는 노드의 다음주소 --> 현재 head가 가리키는 주소
        NewNode->next = head->next;
        
        //head가 가리키는 주소 --> 새로 추가된 노드
        head->next = NewNode;
        
    }
}

void PrintNode(){
    Node *cur = head->next;
    
    while(cur->next!=NULL){
        printf("%d " ,cur->data);
        cur = cur->next;
    }
    printf("%d\n" ,cur->data);
}

void RemoveNode(int remove_data){
    Node *cur = head->next;
    Node *pre = head;
    
    
    //탐색을 통해 삭제할 노드를 cur이 가리키게 하고
    //삭제할 노드의 바로 전 노드를 pre가 가리키게 합니다.
    while(cur->data != remove_data){
        pre = cur;
        cur = cur->next;
    }
    
    //pre가 가리키느 노드의 다음 주소 --> cur이 가리키는 다음 주소
    pre->next = cur->next;
    
    //cur이 가리키는 노드 free
    free(cur);
    free(pre);
}

int main(){
    
    init();
    
    int n;
    int input;
    cin>>n;
    
    //맨 앞에 삽입하기
    for(int i=0;i<n;i++){
        cin>>input;
        Addnode(input);
    }
    
    PrintNode();
    
    int idx;
    printf("Input remove data : ");
    cin>>idx;
    
    RemoveNode(idx);
    
    PrintNode();
    
}
