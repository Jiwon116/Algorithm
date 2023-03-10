#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 부르트포스, 백트래킹

using namespace std;

int arr[11];
int op[4];
int n, result_min = 1000000001, result_max = -1000000001;

void func(int result, int idx) {
    if(idx == n) {
        if(result > result_max) result_max = result;
        if(result < result_min) result_min = result;

        return;
    }

    for(int i = 0; i < 4; ++i) {
        if(op[i] > 0) {
            op[i]--;

            if(i == 0) func(result + arr[idx], idx + 1);
            else if(i == 1) func(result - arr[idx], idx + 1);
            else if(i == 2) func(result * arr[idx], idx + 1);
            else func(result / arr[idx] , idx + 1);

            op[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < 4; ++i) cin >> op[i];

    func(arr[0], 1);

    cout << result_max << '\n' << result_min << '\n';
    
    return 0;
}