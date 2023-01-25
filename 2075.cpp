#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;
 
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num; cin >> num;
            pq.push(num);

            if (pq.size() > n) {
                pq.pop();
            }
        }
    }
 
    cout << pq.top();
    
    return 0;
}