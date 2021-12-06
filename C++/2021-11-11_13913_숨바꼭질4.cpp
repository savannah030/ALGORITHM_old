// parent "배열" 만들기
// https://hazung.tistory.com/134 (파이썬)
#include <bits/stdc++.h>
using namespace std;
int dist[100001];
int parent[100001]; // dist[x]가 최소일때의 값이 저장됨.

void path(int x){ /////////////////////////////////
    vector<int> V;
    int prev = x;
    for (int i=0;i<dist[x]+1;i++){
        V.push_back(prev);
        prev = parent[prev];
    }
    for (auto iter=V.rbegin(); iter!=V.rend(); iter++){
        cout << *iter << " ";
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K; //수빈,동생
    cin >> N >> K;
    queue <int> Q; 
    Q.push(N); 
    fill(dist,dist+100001,-1);
    dist[N]=0;

    while(!Q.empty()){
        int now = Q.front(); Q.pop();
        if (now==K) {
            cout << dist[now] << '\n';
            path(K);
            return 0;
        }
        //for (tuple<int,int> NXT:{{0,now*2},{1,now-1},{2,now+1}}){
        for (auto nxt:{now*2,now-1,now+1}){
            if (nxt<0 or nxt>100000) continue;
            if (dist[nxt]!=-1) continue; //이미 방문한 칸이면
            dist[nxt] = dist[now]+1;
            parent[nxt]=now;
            Q.push(nxt);
        }
    }
}
