#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k; cin >> n >> k;
    
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    int count = 0;

    for(int i = n - 1; i >= 0; --i) {
        count += k / v[i];
        k = k % v[i];
    }

    cout << count << '\n';

    return 0;
}