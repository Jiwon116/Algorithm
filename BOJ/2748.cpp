#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll memo[91];

ll fibo(int n) {

    if(n == 0) return 0;
    if(n == 1) return 1;

    ll &ret = memo[n];
    if(ret != -1) return ret;

    ret = fibo(n - 1) + fibo(n - 2);

    return ret;
}

int main() {
    cin >> n;

    memset(memo, -1, sizeof(memo));

    cout << fibo(n) << '\n';

    return 0;
}