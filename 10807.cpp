#include <iostream>

using namespace std;

int main() {
    int t, n, v;
    int arr[201] = {0, };

    cin >> t;

    for(int i = 0 ; i < t; ++i) {
        cin >> n;
        arr[n + 100]++;
    }

    cin >> v;
    
    cout << arr[v + 100] << '\n';

    return 0;
}