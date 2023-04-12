#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int arr[41] = {0};
int n, cnt1 = 0, cnt2 = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
      cnt1++;
      return 1;  
    }
    else return (fib(n - 1) + fib(n - 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    fib(n);

    arr[1] = arr[2] = 1;

    for(int i = 3; i <= n; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
        cnt2++;
    }

    cout << cnt1 << " " << cnt2 << '\n';
    
    return 0;
}