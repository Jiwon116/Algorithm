#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;

    vector< pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
        int day, pay; cin >> day >> pay;
        v.push_back({day, pay});
    }

    // memo[k] : k 째날 전 까지 얻을 수 있는 최대 이익
    int memo[17];
    memset(memo, 0, sizeof(memo));

    for(int i = 0; i < n; ++i) {
        int next = v[i].first;
        memo[i + 1] = max(memo[i], memo[i + 1]);
        memo[i + next] = max(memo[i + next], memo[i] + v[i].second);
    }

    cout << *max_element(memo, memo + n + 1) << "\n";
    return 0;
}