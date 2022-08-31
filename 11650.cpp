#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector< pair<int, int> > v; 

    while(n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), [] (const pair<int, int> &a, const pair<int, int> &b) -> bool {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    for(pair<int, int> e : v) cout << e.first << " " << e.second << "\n";

    return 0;
}