//벽부수고 이동하기랑 비슷한 유형?
//27분
//+9분 fill 디버깅 (K가 아니라 K+1을 했어야 했음!!!! 생각을 해 생각을!!!!!!)
//3% 메모리초과 
#include <bits/stdc++.h>
using namespace std;

int board[202][202]; //board[i][j][K] <- K번 말처럼 이동했을 때
int dist[202][202][31]; //int dist[31][202][202]으로 해도 됨
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int hx[8]={-2,-1,1,2,2,1,-1,-2};
int hy[8]={1,2,2,1,-1,-2,-2,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K,W,H; //말처럼움직이는최대횟수1<=K<=30,가로W,세로H
    cin >> K >> W >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            int b;
            cin >> b;
            board[i][j]=b;
            fill(dist[i][j],dist[i][j]+K+1,-1); //dist초기화 근데 여기서 실수할 가능성 높을듯
            //dist[i][j][0]=0; ///////////////여기서 초기화하면 안되지!!!!! 처음에는 dist[0][0][0]만 0이어야 하니까 
        }
    }
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0}); //{x,y,말처럼움직인횟수k}
    dist[0][0][0]=0;
    
    while(!Q.empty()){
        int x,y,k;
        tie(x,y,k) = Q.front(); Q.pop();
        if (x==H-1 && y==W-1) { //큐에 k가 작은순으로 들어가기 때문에 이 조건만 만족하면 바로 최솟값!
            cout << dist[x][y][k];
            return 0;
        }
        
        for(int dir=0; dir<4; dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if (nx<0 || nx>=H || ny<0 || ny>=W) continue;
            if (dist[nx][ny][k]!=-1 || board[nx][ny]==1) continue; //이미 방문한 칸이거나 장애물인경우
            dist[nx][ny][k] = dist[x][y][k]+1;
            Q.push({nx,ny,k});     
        }
        if (k>=K) continue;
        for(int dir=0; dir<8; dir++){
            int nx = x+hx[dir];
            int ny = y+hy[dir];
            if (nx<0 || nx>=H || ny<0 || ny>=W) continue;
            if (dist[nx][ny][k+1]!=-1 || board[nx][ny]==1) continue;//이미 방문한 칸이거나 장애물인경우 k+1을 k로 잘못쓰지 않도록 주의!!!
            dist[nx][ny][k+1] = dist[x][y][k]+1;
            Q.push({nx,ny,k+1});  
        } 
    }
    cout << -1;
    /*
    int ans = 0x7f7f7f7f;
    for (int i = 0; i < K + 1; i++)
        if(dist[H-1][W-1][i]!=-1) ///////////////////////
            ans = min(ans,dist[H-1][W-1][i]);
    if (ans != 0x7f7f7f7f) cout << ans;
    else cout << -1;
    */
}