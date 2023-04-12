#include <iostream>
#include <vector>

using namespace std;

vector<int> v(41,-1);

int fibo(int n){
    
    v[0] = 0;
    v[1] = 1;

    if (n == 0) return v[n];
    else if (n == 1) return v[n];
    else if (v[n] == -1) v[n] = fibo(n - 1) + fibo(n - 2);

    return v[n];
}

int main() {
    int n; cin >> n;

    while(n--) {
        int num; cin >> num;

        if (num == 0) cout << 1 << " " << 0 << '\n';
        else cout << fibo(num - 1) << " " << fibo(num) <<'\n';
    }

    return 0;
}