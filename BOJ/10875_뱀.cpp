//
//  10875_뱀.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 20..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef struct Node{
    long long t;
    char dir;
}Node;

int dir[4][2] = {
    {0,1} , {1,0} , {0,-1}, {-1,0}
};

int main(){
    long long L,N;
    int k;
    char s;
    vector<Node> v;
    cin>>L>>N;
    
    for(int i=0;i<N;i++){
        cin>>k>>s;
        v.push_back({k,s});
    }
    set<pair<int, int>> visited;
    long long t = 0;
    long long d = 0;
    
    long long cur_x = 0;
    long long cur_y = 0;
    visited.insert({0,0});
    int ans = 0;
    while(1){
        if(v.size()>0){
            long long cur_t = v[0].t;
            char cur_d = v[0].dir;
        
            if(cur_t == t){
                if(cur_d == 'L'){
                    d-=1;
                    if(d<0) d = 3;
                }
                else{
                    d+=1;
                    if(d>3) d = 0;
                }
                t = 0;
                v.erase(v.begin());
            }
        }
        
        long long next_x = cur_x + dir[d][0];
        long long next_y = cur_y + dir[d][1];
        
        if(next_x > L || next_x < -L || next_y > L || next_y < -L){
            ans++;
            cout<<ans<<'\n';
            break;
        }
        
        if(visited.find({next_x,next_y}) == visited.end()){
            visited.insert({next_x,next_y});
            ans++;
            t++;
            cur_x = next_x;
            cur_y = next_y;
        }
        else{
            ans++;
            cout<<ans<<'\n';
            break;
        }
        
    }
}
