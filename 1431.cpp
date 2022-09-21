#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector< pair < pair<int, int>, string > > v;
    while(n--) {
        string s; cin >> s;
        int sum = 0;

        for(auto e : s) {
            if ('0' <= e && e <= '9') sum += e - '0';
        }

        v.push_back({{s.length(), sum}, s});
    }

    sort(v.begin(), v.end());

    for(auto e : v) cout << e.second << '\n';

    return 0;
}