//
//  2477_차량정비소.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 21..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Repair{
    int cus_num;
    int got_time;
    int reception_num;
}Repair;

typedef struct Node{
    int cus_num;
    int need_time;
    int spent_time;
}Node;

Node ar[30];
Node bj[30];
int cus[1003];
int visited[1003];
int N,M,K,A,B;

int cmp(Repair a, Repair b){
    if(a.got_time < b.got_time) return 1;
    else if(a.got_time == b.got_time){
        if(a.reception_num < b.reception_num) return 1;
    }
    return 0;
}

int go(){
    for(int i=0;i<K;i++) visited[i] = 0;
    int time = 0;
    vector<int> Recept_waiting;
    vector<Repair> Repair_waiting;
    vector<int> Alist;
    vector<int> Blist;
    
    //Reception 대기 vector
    while(1){
        //end 조건
        int end_flag = 0;
        for(int i=0;i<K;i++){
            if(visited[i] == 0){
                end_flag = 1;
                break;
            }
        }
        if(end_flag==0) break;
        
        
        //접수데스크가 사람이 있으면 먼저 count 1씩 증가
        for(int i=0;i<N;i++){
            if(ar[i].spent_time>=0){
                ar[i].spent_time+=1;
                if(ar[i].spent_time == ar[i].need_time){
                    //Repair desk 대기 vector로 이동
                    Repair_waiting.push_back({ar[i].cus_num,time,i});
                    //접수데스크 빈자리로 만들기
                    ar[i].spent_time = -1;
                }
            }
        }
        
        //현재 시간에 도착한 고객 있으면 Recept 대기열에 추가
        for(int i=0;i<K;i++){
            if(time == cus[i]){
                Recept_waiting.push_back(i);
            }
        }
        
        //Recept 데스트에 빈 창구가 있으면 대기열에서 삭제하고 배치하기
        for(int i=0;i<N;i++){
            if(Recept_waiting.size()==0) break;
            if(ar[i].spent_time == -1){
                ar[i].cus_num = Recept_waiting[0];
                ar[i].spent_time = 0;
                //printf("%d cus -> %d Recept desk\n" , Recept_waiting[0]+1,i+1);
                if(i+1 == A) Alist.push_back(Recept_waiting[0]+1);
                Recept_waiting.erase(Recept_waiting.begin());
            }
        }
        
        ////////////////////////////////////////////////
        //Repair
        
        //Repair 대기열에 있는 사람, 주어진 조건에 맞게 sort
        sort(Repair_waiting.begin(),Repair_waiting.end(),cmp);
        
        //수리데스크에 사람이 있으면 먼저 count 1씩 증가
        for(int i=0;i<M;i++){
            if(bj[i].spent_time>=0){
                bj[i].spent_time+=1;
                if(bj[i].spent_time == bj[i].need_time){
                    //창구비우고, 끝났다는 표시하기
                    visited[bj[i].cus_num] = 1;
                    bj[i].spent_time = -1;
                }
            }
        }
        
        //Repair 대기열에 있는 사람 창구에 배치하기
        for(int i=0;i < M ;i++){
            if(Repair_waiting.size()>0){
                if(bj[i].spent_time == -1){
                    bj[i].cus_num = Repair_waiting[0].cus_num;
                    bj[i].spent_time = 0;
                    //printf("%d cus -> %d Repair desk\n" , bj[i].cus_num+1,i+1);
                    if(i+1 == B)Blist.push_back(bj[i].cus_num+1);
                    Repair_waiting.erase(Repair_waiting.begin());
                }
            }
        }
        
        time++;
    }
    int sum  = 0;
    
    int len1 = (int)Alist.size();
    int len2 = (int)Blist.size();
    
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(Alist[i] == Blist[j]){
                sum += Alist[i];
                break;
            }
        }
    }
    
    return sum;
}

void solve(int tc){
    
    cin>>N>>M>>K>>A>>B;
    for(int i=0;i<N;i++){
        cin>>ar[i].need_time;
        ar[i].spent_time = -1;
        ar[i].cus_num  = -1;
    }
    for(int i=0;i<M;i++){
        cin>>bj[i].need_time;
        bj[i].spent_time = -1;
        bj[i].cus_num = -1;
    }
    for(int i=0;i<K;i++) cin>>cus[i];
    int ans = go();
    if(ans == 0) ans = -1;
    
    cout<<'#'<<tc<<' '<<ans<<'\n';
}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}
