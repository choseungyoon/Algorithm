#include <cstdio>
#include <algorithm>
using namespace std;
char a[26][26];
int r, c, visited[26][26], b[26][26];
pair<int, int> s;
pair<int, int> e;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool chk(int x, int y) {
    return 0 <= x&&x<r && 0 <= y&&y<c;
}
void dfs(int x, int y) {
    visited[x][y] = true;
    int cx, cy;
    if (a[x][y] == 'M' || a[x][y] == '+') {
        for (int i = 0; i<4; i++) {
            cx = x + dx[i];
            cy = y + dy[i];
            if (!chk(cx, cy) || visited[cx][cy])
                continue;
            if (a[x][y] == 'M' && a[cx][cy] == '.')
                continue;
            dfs(cx, cy);
        }
    }
    else if (a[x][y] == '|') {
        cx = x + 1;
        cy = y;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
        cx = x - 1;
        cy = y;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
    }
    else if (a[x][y] == '-') {
        cx = x;
        cy = y + 1;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
        cx = x;
        cy = y - 1;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
    }
    else if (a[x][y] == '1') {
        cx = x;
        cy = y + 1;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
        cx = x + 1;
        cy = y;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
    }
    else if (a[x][y] == '2') {
        cx = x;
        cy = y + 1;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
        cx = x - 1;
        cy = y;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
    }
    else if (a[x][y] == '3') {
        cx = x - 1;
        cy = y;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
        cx = x;
        cy = y - 1;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
    }
    else if (a[x][y] == '4') {
        cx = x + 1;
        cy = y;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
        cx = x;
        cy = y - 1;
        if (chk(cx, cy) && !visited[cx][cy]) {
            dfs(cx, cy);
        }
    }
    else if (a[x][y] == '.')
        e = { x,y };
}
int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i<r; i++) {
        getchar();
        for (int j = 0; j<c; j++) {
            scanf("%c", &a[i][j]);
            if (a[i][j] == 'M')s = { i,j };
        }
    }
    dfs(s.first, s.second);
    printf("%d %d ", e.first + 1, e.second + 1);
    int x = e.first;
    int y = e.second;
    if (chk(x + 1, y) && (a[x + 1][y] == '+' || a[x + 1][y] == '|' || a[x + 1][y] == '2' || a[x + 1][y] == '3'))
        b[x + 1][y] = 1;
    if (chk(x - 1, y) && (a[x - 1][y] == '+' || a[x - 1][y] == '|' || a[x - 1][y] == '1' || a[x - 1][y] == '4'))
        b[x - 1][y] = 1;
    if (chk(x, y + 1) && (a[x][y + 1] == '+' || a[x][y + 1] == '-' || a[x][y + 1] == '4' || a[x][y + 1] == '3'))
        b[x][y + 1] = 1;
    if (chk(x, y - 1) && (a[x][y - 1] == '+' || a[x][y - 1] == '-' || a[x][y - 1] == '2' || a[x][y - 1] == '1'))
        b[x][y - 1] = 1;
    if (chk(x + 1, y) && chk(x, y + 1) && chk(x - 1, y) && chk(x, y - 1) && b[x + 1][y] && b[x][y + 1] && b[x - 1][y] && b[x][y - 1])
        printf("+");
    else if (chk(x + 1, y) && chk(x - 1, y) && b[x + 1][y] && b[x - 1][y])
        printf("|");
    else if (chk(x, y + 1) && chk(x, y - 1) && b[x][y + 1] && b[x][y - 1])
        printf("-");
    else if (chk(x + 1, y) && chk(x, y + 1) && b[x + 1][y] && b[x][y + 1])
        printf("1");
    else if (chk(x - 1, y) && chk(x, y + 1) && b[x - 1][y] && b[x][y + 1])
        printf("2");
    else if (chk(x - 1, y) && chk(x, y - 1) && b[x - 1][y] && b[x][y - 1])
        printf("3");
    else if (chk(x + 1, y) && chk(x, y - 1) && b[x + 1][y] && b[x][y - 1])
        printf("4");
    return 0;
}
