#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    priority_queue<int> pq;

    while(n--) {
        int num; cin >> num;

        if(num == 0) {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << -(pq.top()) << '\n';
                pq.pop();
            }
        } else {
            pq.push(-num);
        }
    }

    return 0;
}