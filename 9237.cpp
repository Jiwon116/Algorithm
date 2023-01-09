#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i) cin >> v[i];

    sort(v.rbegin(), v.rend()); // 나무가 자라는데 오래 걸리는 순으로 정렬

    int ans = 0;

    for(int i = 0; i < n; ++i) ans = max(ans, v[i] + i); // 날이 지난 만큼 값 더해주기

    cout << ans + 2 << '\n'; // 나무 사기 + 나무 심기 = 2
    
    return 0;
}