#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> v;
    int sum1 = 0;
    
    for(int i = 0; i < 10; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    for(int i = 0; i < 10; ++i) {
        int sum2 = sum1 + v[i];
        if(sum2 >= 100) {
            if(sum2 - 100 <= 100 - sum1) cout << sum2 << '\n';
            else cout << sum1 << '\n';
        }
        sum1 = sum2;
    }

    cout << sum1 << '\n';
    
    return 0;
}