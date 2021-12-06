//덩어리 세는 문제
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; //테스트케이스 수
    cin >> T;
    for (int t=0; t<T; t++){
        int M,N,K; //가로,세로,위치의개수
        cin >> M >> N >> K;
        int board[N][M];
        for(int i=0;i<N;i++) fill(board[i],board[i]+M,0);
        for(int k=0;k<K;k++){
            int x,y;
            cin >> x >> y;
            board[y][x]=1; //문제를 잘읽자.. 
        }
        /*
        for(int i=0; i<N; i++){
            for(int j=0;j<M;j++){
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        */
        int worm = 0;
        for(int i=0; i<N; i++){
            for(int j=0;j<M;j++){

                if (board[i][j]==0) continue;
                worm++;
                queue<pair<int,int>> Q;
                Q.push({i,j});
                board[i][j]=0; //vis[i][j]=true;

                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X+dx[dir];
                        int ny = cur.Y+dy[dir];
                        if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
                        if (board[nx][ny]==0) continue;
                        Q.push({nx,ny});
                        board[nx][ny]=0; //vis[nx][ny]=true;
                    }

                }
            }
        }
        cout << worm << '\n';
    }
}
