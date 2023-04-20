#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;

    while(true) {
        cin >> n;

        int cnt = 0;

        if(!n) break;

        for(int i = n + 1; i <= 2 * n; ++i) {
            int num = sqrt(i);

            if(num == 1 && i != 1) {
                cnt++;
                continue;
            }

            if(i % 2) {
                for(int j = 2; j <= num; ++j) {
                    if(!(i % j)) break;
                    if(j == num) cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
    
    return 0;
}