//22분
//우선 fdist를 끝까지 만들고 jdist에서 fdist의 조건을 확인해주는 방법 
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1002][1002];
int jdist[1002][1002];
int fdist[1002][1002];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R,C; //행,열
    cin >> R >> C;
    queue<pair<int,int>> jQ;
    queue<pair<int,int>> fQ;
    for(int i=0; i<R; i++) {
        fill(jdist[i],jdist[i]+C,-1); //dist 초기화
        fill(fdist[i],fdist[i]+C,-1);
    }
    
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            char b;
            cin >> b;
            if (b=='F')  { 
                b='.'; 
                fQ.push({i,j}); 
                fdist[i][j] = 0;
            }
            else if (b=='J') {  //J는 입력에서 하나만 주어진다.
                b='.'; 
                jQ.push({i,j}); 
                jdist[i][j] = 0;
            }
            board[i][j]=b;            
        }
    }
    
    cout << "board\n";
    for(int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cout << board[i][j];
        }
        cout <<'\n';
    }
    cout << "jdist\n";
    for(int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cout << jdist[i][j];
        }
        cout <<'\n';
    }
    cout << "fdist\n";
    for(int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cout << fdist[i][j];
        }
        cout <<'\n';
    }
    
    // 불 전파
    while(!fQ.empty()){
        auto cur = fQ.front(); fQ.pop();
        for (int dir=0; dir<4; dir++){
            int nx = cur.X+dx[dir]; 
            int ny = cur.Y+dy[dir];
            if (nx<0 || nx>=R || ny<0 || ny>=C) continue;
            if (fdist[nx][ny]>=0 || board[nx][ny]=='#') continue; //이미 방문했거나 벽이면
            fdist[nx][ny]=fdist[cur.X][cur.Y]+1;
            fQ.push({nx,ny});  
        }
    }
    // 지훈 달리기
    while(!jQ.empty()){
        auto cur = jQ.front(); jQ.pop();
        for (int dir=0; dir<4; dir++){
            int nx = cur.X+dx[dir]; 
            int ny = cur.Y+dy[dir];
            // 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
            if (nx<0 || nx>=R || ny<0 || ny>=C) {
                cout << jdist[cur.X][cur.Y]+1;
                return 0;
            }
            if (jdist[nx][ny]>=0 || board[nx][ny]=='#') continue; //이미 방문했거나 벽이면
            if (fdist[nx][ny]!=-1 && fdist[nx][ny]<=jdist[cur.X][cur.Y]+1) continue; //(nx,ny)에 불이 더 빨리 전파되면
            //jdist[nx][ny]는 -1이니까 jdist[cur.X][cur.Y]+1 써야함
            jdist[nx][ny]=jdist[cur.X][cur.Y]+1;
            jQ.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
}