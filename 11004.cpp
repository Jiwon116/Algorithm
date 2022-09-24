#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<int> v;
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    
    cout << v[k - 1] << '\n';

    return 0;
}