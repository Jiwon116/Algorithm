#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 비트마스킹

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<pii> v;
    int ans = 1e9;
    
    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    for(int i = 1; i < (1 << n); ++i) { // 1 << n -> 1을 왼쪽으로 n칸 이동
        int sour = 1, bitter = 0;
        for(int j = 0; j < n; ++j) {
            if(i & (1 << j)) { // i에 원소가 있는지 확인
                sour *= v[j].first;
                bitter += v[j].second;
            }
        }

        ans = min(ans, abs(sour - bitter));
    }

    cout << ans << '\n';
    
    return 0;
}