//25분 3%에서 틀렸다고 나옴 졸려서 집중안됨. 내일 풀어야지
// 이 문제는 for(start)대신에 while(start<end 써야함)
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; //전체 용액의 수
    cin >> N; //2<=N<=100,000
    vector<int> V;
    int fluid;
    for (int i=0;i<N;i++){
        cin >> fluid;
        V.push_back(fluid);
    }
    sort(V.begin(),V.end());

    int st = 0;
    int en = N-1;
    int MIN = 0x7fffffff;
    int ans1,ans2;
    // MIN 갱신한 다음에 end,start 중 뭐 움직일지 선택할 수 있어야 하는데 
    // 이 코드는 무조건 start 움직임
    // 유형에 맞는 투 포인터 템플릿 뭔지 판단하기 어렵다..
    // start, end가 둘 다 왼->오면 for문 템플릿써도 되지만 
    // 이 문제처럼 end는 오->왼인 경우는 while문 쓰는 게 나음
    while (st<en){
        int sum = V[st]+V[en];
        if (MIN>abs(sum)){
            MIN = abs(sum);
            ans1 = V[st];
            ans2 = V[en];
            //cout << "cand " << ans1 << ' ' << ans2 << '\n';
        }
        if (sum>0) en--; /////////////// V는 정렬된 데이터이므로 sum이 양수/음수냐에 따라 st,en 중 뭘 조절할지 판단할 수 있음
        else if (sum<0) st++;
        else break; //V[st]+V[en]==0
}
    /*
    for(int st=0;st<N;st++){
        while (en>st && abs(V[st]+V[en])>MIN) en--;
        if (en<st) break;
        if (MIN>abs(V[st]+V[en])){
            MIN = abs(V[st]+V[en]);
            ans1 = V[st];
            ans2 = V[en];
            cout << "cand" << ans1 << ' ' << ans2 << '\n';
        }
    }
    */
    cout << ans1 << ' ' << ans2 << '\n';
}