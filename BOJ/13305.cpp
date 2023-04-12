#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 그리디

using namespace std;

int n;
vector<ll> v;
vector<ll> cost;
ll answer = 0;

ll greedy() {
    ll min_cost = cost[0];
    answer += cost[0] * v[0];

    for(int i = 1; i < cost.size() - 1; ++i) {
        if(cost[i] > min_cost) answer += min_cost * v[i];
        else {
            min_cost = cost[i];
            answer += min_cost * v[i];
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int i = 0; i < n - 1; ++i) {
        ll num; cin >> num;
        v.push_back(num);
    }

    for(int i = 0; i < n; ++i) {
        ll num; cin >> num;
        cost.push_back(num);
    }

    cout << greedy() << '\n';

    return 0;
}