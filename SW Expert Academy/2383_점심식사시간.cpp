//
//  2383_점심식사시간.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 16..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef struct Node{
    int idx;
    int x;
    int y;
}Node;

typedef struct Node1{
    int idx;
    int x;
    int y;
    int dis;
}Node1;

typedef struct Stare{
    int idx;
    int spent;
}Stare;

int arr[15][15];
int people[15];

queue<Node> person_info;
Node s1,s2;
int ans = 0;

void BFS(){
    queue<Node1> group1;
    queue<Node1> group2;
    int finish[15];
    for(int i=0;i<15;i++) finish[i] = 0;
    
    int num = (int)person_info.size();
    
    //Divide Group
    for(int i=0;i<num;i++){
        Node tmp = person_info.front();
        person_info.pop();
        if(people[i] == 1){
            group1.push({tmp.idx,tmp.x,tmp.y,abs(s1.x - tmp.x) + abs(s1.y - tmp.y)});
        }
        else{
            group2.push({tmp.idx,tmp.x,tmp.y,abs(s2.x - tmp.x) + abs(s2.y - tmp.y)});
        }
        person_info.push(tmp);
    }
    
    int time = 1;
    vector<Stare> one;
    vector<Stare> two;
    
    while(1){
        //Group1 start
        
        //계단 먼저
        int wait_one = (int)one.size();
        if(wait_one > 0){
            int delete_cnt = 0;
            for(int i=0;i<wait_one;i++){
                if(i>2) break;
                if(one[i].spent + 1 == arr[s1.x][s1.y]){
                    //탈출성공
                    finish[one[i].idx] = 1;
                    delete_cnt++;
                }
                else{
                    one[i].spent += 1;
                }
            }
            for(int i=0;i<delete_cnt;i++){
                one.erase(one.begin());
            }
        }
        
        int g1_cnt = (int)group1.size();
        
        for(int i=0 ; i<g1_cnt;i++){
            Node1 tmp = group1.front();
            group1.pop();
            if(time == tmp.dis){
                //계단도착
                one.push_back({tmp.idx,0});
            }
            else{
                group1.push(tmp);
            }
        }
        
        //Group2 start
        
        //계단 먼저
        int wait_two = (int)two.size();
        if(wait_two > 0){
            int delete_cnt = 0;
            for(int i=0;i<wait_two;i++){
                if(i>2) break;
                if(two[i].spent + 1 == arr[s2.x][s2.y]){
                    //탈출성공
                    finish[two[i].idx] = 1;
                    delete_cnt++;
                }
                else{
                    two[i].spent+=1;
                }
            }
            for(int i=0;i<delete_cnt;i++){
                two.erase(two.begin());
            }
        }
        
        int g2_cnt = (int)group2.size();
        
        for(int i=0 ; i<g2_cnt;i++){
            Node1 tmp = group2.front();
            group2.pop();
            if(time == tmp.dis){
                //계단도착
                two.push_back({tmp.idx,0});
            }
            else{
                group2.push(tmp);
            }
        }
        int end_flag = 0;
        
        for(int i=0;i<num;i++){
            if(finish[i]==0){
                end_flag = 1;
                break;
            }
        }
        
        if(end_flag == 0){
            if(ans > time) ans = time;
            break;
        }
        else{
            time++;
            if(time > ans) break;
        }
        
    }
    
}

void SetGroup(int cur, int cnt_person){
    if(cur==cnt_person){
        //탐색시작
        //BFS
        BFS();
        return;
    }
    
    
    //group1에 배정
    people[cur] = 1;
    SetGroup(cur+1, cnt_person);
    people[cur] = 0;
    
    //group2에 배정
    people[cur] = 2;
    SetGroup(cur+1, cnt_person);
    people[cur] = 0;
    
}

void solve(int tc){
    
    int n;
    cin>>n;
    int idx = 0;
    ans = 100000;
    int flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]>1){
                if(flag==0){
                    s1.x = i, s1.y=j;
                    flag= 1;
                }
                else{
                    s2.x = i, s2.y=j;
                }
            }
            else if(arr[i][j] == 1){
                person_info.push({idx,i,j});
                idx++;
            }
        }
    }
    
    SetGroup(0,(int)person_info.size());
    
    cout<<'#'<<tc<<' '<<ans+1<<'\n';
    while(!person_info.empty()){
        person_info.pop();
    }
}

int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++) solve(i);
    
}
