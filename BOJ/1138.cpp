#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    vector<int> v(n + 1);
    vector<int> answer(n + 1);

    for(int i = 1; i <= n; ++i) cin >> v[i]; // 2 1 1 0

    for(int i = 1; i <= n; ++i) {
        int index = 0;

        for(int j = 1; j <= n; ++j) {
            if(answer[j] == 0) index++;

            if(index > v[i]) {
                answer[j] = i;
                break;
            }
        }
    }

    for(int i = 1; i<= n; ++i) cout << answer[i] << " "; cout << '\n';
    
    return 0;
}