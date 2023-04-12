#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;

    for(int i = 0; i < 1001; ++i) v.push_back(i);

    v[0] = 0;
    v[1] = 0;

    for(int i = 2; i < sqrt(1001); ++i) {
        if(v[i] == 0) continue;

        for(int j = i * i; j < 1001; j = j + i) v[j] = 0;
    }

    
    int n; cin >> n;

    int cnt = 0;

    while (n--) {
        int num; cin >> num;
        if (v[num] != 0) cnt++;
    }

    cout << cnt << '\n';
    
    return 0;
}