#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, left = 0, right = 0, sum = 0, cnt = 0;
    int arr[10001];

    cin >> n >> m;

    for(int i = 0; i < n; ++i) cin >> arr[i];

    while(left <= right) {
        if(sum == m) cnt++;

        if(sum >= m) {
            sum -= arr[left];
            left++;
        } else if (right >= n) break;
        else {
            sum += arr[right];
            right++;
        }
    }

    cout << cnt << '\n';
    
    return 0;
}