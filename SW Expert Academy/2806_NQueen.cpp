#include<iostream>
#include <stdio.h>
#include<stack>
#include<map>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<functional>
#include <string>
using namespace std;

bool arr[15][15];
int ans = 0;

bool check(int row, int col,int n) {
    // |
    for (int i=1; i<=n; i++) {
        if (i == row) continue;
        if (arr[i][col]) {
            return false;
        }
    }
    // 왼쪽 위 대각선
    int x = row-1;
    int y = col-1;
    while (x >=1 && y >=1) {
        if (arr[x][y] == true) {
            return false;
        }
        x -= 1;
        y -= 1;
    }
    // /
    x = row-1;
    y = col+1;
    while (x >=1 && y <=n) {
        if (arr[x][y] == true) {
            return false;
        }
        x -=1;
        y += 1;
    }
    return true;
}

void calc(int row, int n) {
    if (row == n+1) {
        ans += 1;
    }
    for (int col=1; col<=n; col++) {
        arr[row][col] = true;
        if (check(row, col,n)) {
            calc(row+1,n);
        }
        arr[row][col] = false;
    }
}

void solve(int tc){
    ans = 0;
    int n;
    cin>>n;
    calc(1,n);
    
    cout<<'#'<<tc<<' ';
    cout<<ans<<'\n';
}

int main(void) {
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++) solve(i);
    
    return 0;
}

