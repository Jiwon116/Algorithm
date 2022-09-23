#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector< pair < pair<int, int>, string> > v;

    for(int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;

        v.push_back({{age, i}, name});
    }

    sort(v.begin(), v.end());

    for(auto e : v) cout << e.first.first << " " << e.second << '\n';

    return 0;
}