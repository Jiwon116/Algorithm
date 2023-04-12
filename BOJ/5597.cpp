#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v(31, 0);

    int n;
    while(cin >> n) {
        v[n] = 1;
    }

    for(int i = 1; i <= 30; ++i) {
        if(v[i] == 0) cout << i << '\n';
    }

    return 0;
}