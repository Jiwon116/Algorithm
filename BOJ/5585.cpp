#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    vector<int> v = {500, 100, 50, 10, 5, 1};

    int rest = 1000 - n;
    int answer = 0;

    for(int i = 0; i < v.size(); ++i) {
        while(rest >= v[i]) {
            rest -= v[i];
            answer++;
        }
    }

    cout << answer << '\n';
    
    return 0;
}