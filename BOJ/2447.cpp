#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

void func(int num, int x, int y) {
    if((x / num) % 3 == 1 && (y / num) % 3 == 1) cout << ' ';
    else {
        if(num / 3 == 0) cout << "*";
        else func(num / 3, x, y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) func(n, i, j);
        cout << '\n';
    }
    
    return 0;
}