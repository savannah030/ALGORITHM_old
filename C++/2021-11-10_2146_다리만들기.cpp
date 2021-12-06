// 최소점일 때 빠져나와야하는 문제(<- 말 좀 더 예쁘게 정리) 아니기 때문에 vis 따로 만들 필요 없을듯
// 파이썬 코드에서는 어떻게 썼었나 확인
// 30분 indexing까지(시간줄이기!!!)
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[102][102];
int index[102][102];
int dist[102][102];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N; //지도의크기 N

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
	for(int i=0; i<N; i++) memcpy(index[i],board[i],sizeof(board[i]));
	//for(int i=0; i<N; i++) for(int j=0; j<N; j++) index[i][j]=board[i][j]; //값 복사
	// indexing
    int idx = 2;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
			if (index[i][j]!=1) continue; //이미 인덱싱했거나 바다면
			queue<pair<int,int>> Q;
			Q.push({i,j});
			index[i][j]=idx;
			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				for (int dir=0; dir<4; dir++){
					int nx = cur.X+dx[dir];
					int ny = cur.Y+dy[dir];
					if (nx<0 || nx>=N || ny<0 || ny>=N) continue;
					if (index[nx][ny]!=1) continue;   
					Q.push({nx,ny});
					index[nx][ny]=idx;
        		}
    		}
			idx++;
        }
    }
	/*
	cout << "board\n";
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "index\n";
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << index[i][j] << ' ';
        }
        cout << '\n';
    }
	*/
    /*
    2 2 2 0 0 0 0 3 3 3
    2 2 2 2 0 0 0 0 3 3
    2 0 2 2 0 0 0 0 3 3
    0 0 2 2 2 0 0 0 0 3
    0 0 0 2 0 0 0 0 0 3
    0 0 0 0 0 0 0 0 0 3
    0 0 0 0 0 0 0 0 0 0
    0 0 0 0 4 4 0 0 0 0
    0 0 0 0 4 4 4 0 0 0
    0 0 0 0 0 0 0 0 0 0*/

	//응용2 시작점이 여러개일때 -> 큐에 시작점 다넣기
	for(int i=0; i<N; i++) { fill(dist[i],dist[i]+N,-1); } //dist배열 -1로 초기화
	queue<pair<int,int>> Q;
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
			if(board[i][j]==1)  {
				Q.push({i,j}); 
				dist[i][j]=0; ////////
			}
		}
	}
	// finding minimum bridge
	int ans =  0x7f7f7f7f;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++){
			int nx = cur.X+dx[dir];
			int ny = cur.Y+dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=N) continue;
			//if (dist[nx][ny]!=-1) continue;   //이미 방문한 칸이면  ////////////이거 쓰면 안됨. ans = min(...)에서 dist 활용하니까!!!!
			if (index[nx][ny]==index[cur.X][cur.Y]) continue;
			else if (index[nx][ny]==0) {
				dist[nx][ny] = dist[cur.X][cur.Y]+1;
				index[nx][ny] = index[cur.X][cur.Y];
				Q.push({nx,ny});
			}
			else { //인덱스 다른 칸을 만나면 ans만 고치고 Q.push안하기 때문에 무한루프 안생김
				ans = min(ans,dist[cur.X][cur.Y]+dist[nx][ny]);  ///////////////
			}
		}
	}
	cout << ans;	
}
// 바킹독님 코드
/*
# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a / GCD(a, b) * b; }
ll INV(ll a, ll m) {
	ll m0 = m, y = 0, x = 1;
	if (m == 1)	return 0;
	while (a > 1) {
		ll q = a / m;
		ll t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) x += m0;
	return x;
}
pll EXGCD(ll a, ll b) {
	if (b == 0) return { 1,0 };
	auto t = EXGCD(b, a%b);
	return { t.second,t.first - t.second*(a / b) };
}
bool OOB(ll x, ll y, ll N, ll M) { return 0 > x || x >= N || 0 > y || y >= M; }
#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define sf1(a) cin >> a
#define sf2(a,b) cin >> a >> b
#define sf3(a,b,c) cin >> a >> b >> c
#define sf4(a,b,c,d) cin >> a >> b >> c >> d
#define sf5(a,b,c,d,e) cin >> a >> b >> c >> d >> e
#define sf6(a,b,c,d,e,f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << (a) << ' '
#define pf2(a,b) cout << (a) << ' ' << (b) << ' '
#define pf3(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << ' '
#define pf4(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '
#define pf5(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' '
#define pf6(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << ' '
#define pf0l() cout << '\n';
#define pf1l(a) cout << (a) << '\n'
#define pf2l(a,b) cout << (a) << ' ' << (b) << '\n'
#define pf3l(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << '\n'
#define pf4l(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << '\n'
#define pf5l(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << '\n'
#define pf6l(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << '\n'
#define pfvec(V) for(auto const &t : V) pf1(t)
#define pfvecl(V) for(auto const &t : V) pf1(t); pf0l()
int N;
int board[105][105];
int group[105][105];
int depth[105][105];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	sf1(N);
	rep(i, 0, N) rep(j, 0, N) sf1(board[i][j]);
	rep(i, 0, N) rep(j, 0, N) depth[i][j]=-1;

	int gidx = 1;
	rep(i, 0, N) {
		rep(j, 0, N) {
			if (board[i][j] == 1 && group[i][j] == 0) {
				group[i][j] = gidx;
				queue<pii> Q;
				Q.push({ i,j });
				while (!Q.empty()) {
					pii cur = Q.front();
					Q.pop();
					depth[cur.X][cur.Y] = 0;
					rep(dir, 0, 4) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (OOB(nx, ny, N, N)) continue;
						if (board[nx][ny] == 1 && group[nx][ny] == 0) {
							Q.push({ nx,ny });
							group[nx][ny] = gidx;
						}
					}
				}
				gidx++;

			}
		}
	}
	int ans = INF;
	queue<pii> Q;
	rep(i, 0, N) {
		rep(j, 0, N) {
			if (board[i][j] == 1)
				Q.push({ i,j }); //1인애들 좌표값 다 집어넣음
		}
	}
	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();
		int myGroup = group[cur.X][cur.Y];
		int myDepth = depth[cur.X][cur.Y];
		rep(dir, 0, 4) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny, N, N)) continue;
			if (group[nx][ny] == myGroup) continue;
			else if (group[nx][ny] == 0) {
				group[nx][ny] = myGroup;
				depth[nx][ny] = myDepth+1;
				Q.push({ nx,ny });
			}
			else {
				ans = min(ans, depth[nx][ny] + myDepth); 
                //depth[nx][ny]=다른섬의깊이
                //myDepth=내섬의깊이
                //1인애들 좌표값 다 집어넣었으므로 중간에 이렇게 만날 수 있음
			}
		}
	}

	pf1l(ans);
}
*/