#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
vector<int> v;
set< vector<int> > answer;

void backtrack(vector<int> perm) {
    if (perm.size() == m) {
        answer.insert(perm);
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(perm.empty()) {
            perm.push_back(v[i]);
            backtrack(perm);
            perm.pop_back();
        }
        else {
            int num = perm.back();
            if(num <= v[i]) {
                perm.push_back(v[i]);
                backtrack(perm);
                perm.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end()); 

    vector<int> perm;

    backtrack(perm);

    for(auto e : answer) {
        for(auto ele : e) cout << ele << " ";
        cout << '\n';
    }
    
    return 0;
}