#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int k;
int a[101];
int b[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> k;

    a[0] = 1;
    b[0] = 0;
    a[1] = 0;
    b[1] = 1;
    a[2] = 1;
    b[2] = 1;

    // b -> ba
    // a -> b
    for(int i = 3; i <= k; ++i) {
        a[i] = b[i - 1];    // a의 개수는 이전 순서에서의 b의 개수
        b[i] = b[i - 1] + a[i - 1]; // b의 개수는 이전 순서에서의  b와 a의 개수
    }

    cout << a[k] << " " << b[k] << '\n';

    
    return 0;
}