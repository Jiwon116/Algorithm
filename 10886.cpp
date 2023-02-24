#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    int zero_cnt = 0, one_cnt = 0;

    while(n--) {
        int i; cin >> i;

        if(i) one_cnt++;
        else zero_cnt++;
    }

    if(one_cnt >= zero_cnt) cout << "Junhee is cute!\n";
    else cout << "Junhee is not cute!\n";
    
    return 0;
}