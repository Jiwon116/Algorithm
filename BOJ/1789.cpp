#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n; cin >> n;

    ll sum = 0, num = 1;

    while(1) {
        sum += num;
        if(n < sum) break;
        num++;
    }

    cout << num - 1 << '\n';

    return 0;
}