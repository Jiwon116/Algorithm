#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    vector<int> v;

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    // 산술평균
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += v[i];
    }

    float avg = (float)sum / (float)n;
    cout << (int)round(avg) << '\n';

    // 중앙값
    sort(v.begin(), v.end());
    cout << v[n/2] << '\n';

    // 최빈값
    map<int, int> m;
    int max_cnt = 0;
    for(int i = 0; i < n; ++i) {
        m[v[i]]++;
        max_cnt = max(max_cnt, m[v[i]]);
    }

    vector<int> max_answer;
    for(auto e : m) {
        if(e.second == max_cnt) max_answer.push_back(e.first);
    }

    if(max_answer.size() >= 2) cout << max_answer[1] << '\n';
    else cout << max_answer[0] << '\n';

    // 범위
    cout << v[n - 1] - v[0] << '\n';
    
    return 0;
}