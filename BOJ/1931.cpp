#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    vector<pii> v;

    for(int i = 0; i < n; ++i) {
        int start, end; cin >> start >> end;
        v.push_back({end, start});
    }

    sort(v.begin(), v.end()); // 끝나는 시간을 기준으로 정렬

    int start_time = v[0].first; // 가장 빠른 끝나는 시간부터 시작
    int answer = 1;

    for(int i = 1; i < n; ++i) {
        if(start_time <= v[i].second) {
            answer++;
            start_time = v[i].first;
        }
    }

    cout << answer << '\n';
    
    return 0;
}