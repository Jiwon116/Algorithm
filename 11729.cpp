#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

void solution(int cnt, int from, int to) {

    if(cnt == 0) return;

    solution(cnt - 1, from, 6 - from - to);
    cout << from << " " << to << '\n';
    solution(cnt - 1, 6 - from - to, to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    cout << (int)pow(2, n) - 1 << '\n';

    solution(n, 1, 3);
    
    return 0;
}