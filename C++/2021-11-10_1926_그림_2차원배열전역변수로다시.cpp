//32분 bfs 연습 더 열심히!!!
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502]; //이 문제는 다시 방문하는 일이 없기 때문에 (덩어리 수 세는 거니까) 전역변수로 써도 상관없음
int n,m; //세로,가로
int dx[4] = {0,0,1,-1}; //동서남북
int dy[4] = {1,-1,0,0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> board[i][j];

    int cnt=0,MAX=0; //그림의개수,그림최대크기
    //int cnt,MAX = 0; 이런식으로 선언하면 cnt 쓰레기값!!
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (vis[i][j] || board[i][j]!=1) continue;
            cnt++;

            queue<pair<int,int>> Q;
            Q.push({i,j});
            vis[i][j]=1; //까먹으면 안돼!!!!!

            int area = 0; //그림의크기
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X+dx[dir];
                    int ny = cur.Y+dy[dir];
                    if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if (vis[nx][ny] || board[nx][ny]!=1) continue;
                    vis[nx][ny]=1;
                    Q.push({nx,ny});
                    area++;
                }
            }
            MAX = max(MAX,area);
        }
    }
    cout << cnt << '\n' << MAX;
}