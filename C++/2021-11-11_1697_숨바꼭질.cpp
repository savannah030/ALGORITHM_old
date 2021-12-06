//8분30초 6%에서 메모리초과
//17분 6%에서 시간초과 아 그냥 다익스트라로 풀까..
#include <bits/stdc++.h>
using namespace std;
int dist[100001]; /////////// 다시 방문하지 않도록!!!!

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K; //수빈위치N,동생위치K 0 ≤ N,K ≤ 100,000
    cin >> N >> K;

    queue <int> Q;
    Q.push(N); //{현재수빈위치,걸린시간}
    fill(dist,dist+100001,-1); //초기화
    dist[N]=0;

    while(!Q.empty()){
        int now;
        auto now = Q.front(); Q.pop();
        if (now==K) {
            cout << dist[now];
            return 0;
        }
        for (auto nxt: {2*now,now-1,now+1}){
            if (nxt<0 || nxt>100000) continue;
            if (dist[nxt]!=-1) continue; //이미 방문한 위치면(이거 안하면 메모리 초과)
            Q.push(nxt);
            dist[nxt]=dist[now]+1;
        }
    }
    /*
    vector <tuple<int,int>> V;
    V.push_back({N,0}); //{현재수빈위치,걸린시간}
    int now,time;
    while(!V.empty()){
        tie(now,time) = V.front(); V.erase(V.begin()); ///////
        if (now==K) {
            cout << time;
            return 0;
        }
        for (auto nxt: {2*now,now-1,now+1}){
            if (nxt<0 || nxt>100000) continue;
            if(nxt==2*now) V.insert(V.begin(),{nxt,time+1});
            else V.push_back({nxt,time+1});
        }
    }
    */
}