//
//  1953_탈주범검거.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 10. 16..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int arr[55][55];
int visited[55][55];

typedef struct Node{
    int x;
    int y;
}Node;

int dir[4][2] = {
    {-1,0}, {0,1}, {1,0}, {0,-1}
};

bool bdcheck(int x, int y, int n, int m){
    if(x<0 || x >=n || y<0 || y>=m) return false;
    return true;
}

bool bdcheck2(int x, int y, int k){
    if(visited[x][y] == 1) return false;
    
    if(k==0) if(arr[x][y] == 1 || arr[x][y] == 2 || arr[x][y] == 5 || arr[x][y] == 6 ) return true;
    if(k==1) if(arr[x][y] == 1 || arr[x][y] == 3 || arr[x][y] == 6 || arr[x][y] == 7 ) return true;
    if(k==2) if(arr[x][y] == 1 || arr[x][y] == 2 || arr[x][y] == 4 || arr[x][y] == 7 ) return true;
    if(k==3) if(arr[x][y] == 1 || arr[x][y] == 3 || arr[x][y] == 4 || arr[x][y] == 5 ) return true;
    
    return false;
}

int BFS(int n,int m,int x,int y,int l){
    queue<Node> q;
    q.push({x,y});
    visited[x][y] = 1;
    int ans = 1;
    
    
    for(int i=0;i<l-1;i++){
        int t = (int)q.size();
        
        for(int j=0;j<t;j++){
            x = q.front().x;
            y = q.front().y;
            q.pop();
            if(arr[x][y] == 1){
                //상하좌우
                for(int k=0;k<4;k++){
                    int tempX = x + dir[k][0];
                    int tempY = y + dir[k][1];
                    
                    if(bdcheck(tempX,tempY,n,m) == true){
                        if(bdcheck2(tempX,tempY,k)==true){
                            ans++;
                            visited[tempX][tempY] = 1;
                            q.push({tempX,tempY});
                        }
                    }
                }
            }
            else if(arr[x][y] == 2){
                for(int k=0;k<4;k+=2){
                    int tempX = x + dir[k][0];
                    int tempY = y + dir[k][1];
                    
                    if(bdcheck(tempX,tempY,n,m) == true){
                        if(bdcheck2(tempX,tempY,k)==true){
                            ans++;
                            visited[tempX][tempY] = 1;
                            q.push({tempX,tempY});
                        }
                    }
                }
            }
            else if(arr[x][y] == 3){
                for(int k=1;k<4;k+=2){
                    int tempX = x + dir[k][0];
                    int tempY = y + dir[k][1];
                    
                    if(bdcheck(tempX,tempY,n,m) == true){
                        if(bdcheck2(tempX,tempY,k)==true){
                            ans++;
                            visited[tempX][tempY] = 1;
                            q.push({tempX,tempY});
                        }
                    }
                }
            }
            else if(arr[x][y] == 4){
                for(int k=0;k<2;k++){
                    int tempX = x + dir[k][0];
                    int tempY = y + dir[k][1];
                    
                    if(bdcheck(tempX,tempY,n,m) == true){
                        if(bdcheck2(tempX,tempY,k)==true){
                            ans++;
                            visited[tempX][tempY] = 1;
                            q.push({tempX,tempY});
                        }
                    }
                }
            }
            else if(arr[x][y] == 5){
                for(int k=1;k<3;k++){
                    int tempX = x + dir[k][0];
                    int tempY = y + dir[k][1];
                    
                    if(bdcheck(tempX,tempY,n,m) == true){
                        if(bdcheck2(tempX,tempY,k)==true){
                            ans++;
                            visited[tempX][tempY] = 1;
                            q.push({tempX,tempY});
                        }
                    }
                }
            }
            else if(arr[x][y] == 6){
                for(int k=2;k<4;k++){
                    int tempX = x + dir[k][0];
                    int tempY = y + dir[k][1];
                    
                    if(bdcheck(tempX,tempY,n,m) == true){
                        if(bdcheck2(tempX,tempY,k)==true){
                            ans++;
                            visited[tempX][tempY] = 1;
                            q.push({tempX,tempY});
                        }
                    }
                }
            }
            else if(arr[x][y] == 7){
                for(int k=0;k<4;k+=3){
                    int tempX = x + dir[k][0];
                    int tempY = y + dir[k][1];
                    
                    if(bdcheck(tempX,tempY,n,m) == true){
                        if(bdcheck2(tempX,tempY,k)==true){
                            ans++;
                            visited[tempX][tempY] = 1;
                            q.push({tempX,tempY});
                        }
                    }
                }
            }
        }
    }
    
    return ans;
}

void solve(int tc){
    
    int n,m,x,y,l;
    cin>>n>>m>>x>>y>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            visited[i][j] = 0;
        }
    }
    
    
    
    cout<<'#'<<tc<<' '<<BFS(n,m,x,y,l)<<'\n';

}

int main(){
    int tc;
    cin>>tc;
    
    for(int i=1;i<=tc;i++) solve(i);
}

