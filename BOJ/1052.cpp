#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 비트마스킹

using namespace std;

int count_bits(int n) {
    int shift = 0;

    int ret = 0; // 켜진 비트의 개수
    while ((1 << shift) <= n) {
        if (n & (1 << shift++)) ++ret;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k; cin >> n >> k;

    int answer = 0;
    while (count_bits(n++) > k) ++answer;

    cout << answer << "\n";
    
    return 0;
}