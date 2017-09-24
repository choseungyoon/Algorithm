//
//  2533.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 9. 24..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n;
int ans = 0;

vector<vector<int>> v;
vector<vector<int>> dp;
vector<bool> visit;

void Search(int cur){
    
    //방문체크
    visit[cur] = true;
    
    //dp[i][state]  = i번째 정점을 root로 가지고 있는 서브트리에서의 최소 얼리어답터 수
    //state = 0 -> 현재 정점 i가 얼리어답터가 아닌경우
    //state = 1 -> 현재 정점 i가 얼리어답터인 경우
    
    dp[cur][1] +=1;
    
    for(int next : v[cur]){
        if(visit[next] == false){
            //아직 방문 안했으면
            Search(next);
            
            //현재 정점이 얼리어답터가 아니면 친구가 꼭 얼리어답터야 함
            dp[cur][0] += dp[next][1];
            //현재 정점이 얼리어답터면 친구는 어떻게 되든 상관없으니 작은걸로
            dp[cur][1] += min(dp[next][0],dp[next][1]);
            
        }
    }
    
}

int main(){
    
    cin>>n;
    int a,b;
    v.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, 0));
    visit.assign(n+1,false);
    
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    Search(1);
    
    int ans = min(dp[1][0] , dp[1][1]);
    
    cout<<ans<<'\n';
    
}
