//10분 visited를 각 테트로미노마다 만들면 메모리 초과날 것 같은데..
//dfs 너무 안쓰다보니 기본 템플릿도 까먹음..
//12분 dfs -2-1이런거 만들기로..
#include <bits/stdc++.h>
using namespace std;
int board[502][502];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M; //4<=세로,가로<=500
vector<tuple<pair<int,int>,pair<int,int>,pair<int,int>,pair<int,int>>>; //tetro
int dfs(int x,int y,int depth,set<pair<int,int>> visited){ //find tetromino
    if (depth==3){

    }
    for (int dir=0; dir<4; dir++){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
    
    }
}

void makeTetro(int x,int y,int depth){
    if (depth==0) {
        tuple<pair<int,int>,pair<int,int>,pair<int,int>,pair<int,int>> T;
        T.}
    for (int dir=0; dir<4; dir++){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
    
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j]; //1000이하의자연수
        }
    }
    makeTetro(0);


}