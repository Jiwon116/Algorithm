#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int memo[1001];
int trace[1001];

// dp(i)는 0부터 index(i) 까지의 LIS
int dp(int index) {
    if(index == n - 1) return 1;

    int &ret = memo[index];
    if(ret != -1) return ret;

    ret = 1;

    for(int i = index + 1; i < n; ++i) {
        if(v[i] > v[index]) {
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

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    int answer = 0;
    int start_index = 0;

    for(int i = 0; i < n; ++i) {
        if (answer < dp(i)) start_index = i;
        answer = max(answer, dp(i));
    }

    cout << answer << '\n'; 

    trace[start_index] = answer + 1;
    int target = answer + 1;

    for(int i = 0; i < n; ++i) {
        if(trace[i] == target) {
            cout << v[i] << " ";
            target--;
        }
    }

    return 0;
}