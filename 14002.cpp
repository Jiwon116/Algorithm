#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int memo[1001];
int trace[1001];

// dp(i)는 0부터 index(i) 까지의 LIS
int dp(int index) {

    if(index == 0) return 1;

    int &ret = memo[index];
    if(ret != -1) return ret;

    ret = dp(index - 1);
    for(int i = 0; i <= index - 1; ++i) {
        if(v[i] < v[index]) {
            if(ret < dp(i) + 1) {
                ret = dp(i) + 1;
                trace[i] = ret;
            }
        }
    }

    return ret;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(n - 1) << '\n';

    for(int i = 0; i < n; ++i) cout << trace[i] << " ";

    return 0;
}