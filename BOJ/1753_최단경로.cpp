//
//  1753_최단경로.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 5..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct Node{
    int to;
    int val;
}Node;

typedef struct PQ{
    int idx;
    int d;
    int pre;
}PQ;

int dist[20002];
int v,e;
int start_idx;
vector<vector<Node>> adj;

bool operator < (PQ a, PQ b){
    return a.d>b.d;
}

void dijkstra(int start_idx){
    priority_queue<PQ, vector<PQ>, less<PQ>> q;
    
    //모든 정점들을 힙에 넣는다.
    for(int i=1;i<=v;i++){
        q.push({i,dist[i],-1});
    }
    
    while(!q.empty()){
        int cur_idx = q.top().idx;
        int cur_dist = q.top().d;
        int cur_pre = q.top().pre;
        q.pop();
        
        //기존에 있던 dist와 큐에 있는 d와 비교한다.
        //dist가 더 작으면 연산하지 않고
        //dist가 같거나 크면 연산한다.
        if(dist[cur_idx] < cur_dist) continue;
        else{
            //현재 idx의 인접 정점을 계산하고
            //dist보다 더 작아지는 경우 갱신하고 push한다
            int len = (int)adj[cur_idx].size();
            
            for(int i=0;i<len;i++){
                int tmp_to = adj[cur_idx][i].to;
                int tmp_val = dist[cur_idx] + adj[cur_idx][i].val;
                
                if(dist[tmp_to] > tmp_val){
                    dist[tmp_to] = tmp_val;
                    q.push({tmp_to,tmp_val,cur_idx});
                }
            }
        }
    }
}

int main(){
    
    
    //INPUT
    cin>>v>>e>>start_idx;
    for(int i=0;i<=v;i++) dist[i] = 100;
    dist[start_idx] = 0;
    
    adj.assign(v+1, vector<Node>());
    
    int from, to, val;
    
    for(int i=0;i<e;i++){
        cin>>from>>to>>val;
        adj[from].push_back({to, val});
    }
    
    //START
    dijkstra(start_idx);
    
    for(int i=1;i<=v;i++){
        if(dist[i] == 100) cout<<"INF"<<'\n';
        else cout<<dist[i]<<'\n';
    }
    
}
