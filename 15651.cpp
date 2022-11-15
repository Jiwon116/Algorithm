#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
vector< vector<int> > answer;

void backtrack(vector<int> perm) {
    if(perm.size() == m) {
        answer.push_back(perm);
        return;
    }

    for(int i = 1; i <= n; ++i) {
        perm.push_back(i);
        backtrack(perm);
        perm.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    vector<int> perm;

    backtrack(perm);

    for(auto e : answer) {
        for(auto ele : e) cout << ele << " ";
        cout << '\n';
    }
    
    return 0;
}