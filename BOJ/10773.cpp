#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k; cin >> k;

    stack<int> s;

    for(int i = 0; i < k; ++i) {
        int num; cin >> num;

        if (num == 0) s.pop();
        else s.push(num);
    }
    
    int answer = 0;
    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }

    cout << answer << '\n';
    
    return 0;
}