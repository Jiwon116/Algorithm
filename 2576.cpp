#include <bits/stdc++.h>

#define ll long long

#define pii pair<int, int>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    

    vector<int> v;

    v.resize(8);

    

    for(int i = 0; i < 7; ++i) cin >> v[i];

    

    int sum = 0;

    int min_ans = 1e9;

    for(int i = 0; i < 7; ++i){

       if(v[i] % 2 == 1) { // 홀수

           sum += v[i];

           if(min_ans > v[i]) min_ans = v[i];

       }

    }

    

    if (sum != 0) cout << sum << "\n" << min_ans << "\n";

    else cout << -1 << "\n";

    

    return 0;

}
