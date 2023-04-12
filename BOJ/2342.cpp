#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// DP

using namespace std;

vector<int> v;
int memo[5][5][100001];

int move(int from, int to){
    if(from == to) return 1;

    if(from == 0) return 2;
    else if(from == 1) return to == 3 ? 4 : 3;
    else if(from == 2) return to == 4 ? 4 : 3;
    else if(from == 3) return to == 1 ? 4 : 3;
    else if(from == 4) return to == 2 ? 4 : 3;
}

int dp(int l, int r, int idx) {
    if(idx == v.size()) return 0;

    int& ret = memo[l][r][idx];
    if(ret != -1) return ret;

    return ret = min(move(l, v[idx]) + dp(v[idx], r, idx + 1), move(r, v[idx]) + dp(l, v[idx], idx + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    while(true) {
        int num; cin >> num;

        if(num == 0) break;

        v.push_back(num);
    }

    cout << dp(0, 0, 0) << '\n';
    
    return 0;
}