#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    map<string, int> pokemon;
    vector<string> v;
    v.resize(n + 1);

    for(int i = 1; i <= n; ++i) {
        string name; cin >> name;
        pokemon[name] = i; // [Bulbasaur, 1]
        v[i] = name; // v[1] = Bulbasaur
    }

    for(int i = 0; i < m; ++i) {
        string f; cin >> f;

        if ('0' <= f[0] && f[0] <= '9') cout << v[stoi(f)] << '\n';
        else cout << pokemon[f] << '\n';
    }

    return 0;
}