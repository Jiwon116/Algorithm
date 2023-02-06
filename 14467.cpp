#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int cow[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;

    memset(cow, -1, sizeof(cow));

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        int num, pos; cin >> num >> pos;

        if (cow[num] == -1) cow[num] = pos;
        else if (cow[num] != pos && cow[num] != -1){
            cow[num] = pos;
            cnt++;
        }

    }

    cout << cnt << '\n';
    
    return 0;
}