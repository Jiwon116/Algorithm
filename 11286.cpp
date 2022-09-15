#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    priority_queue< pair<int, int> > pq;

    while(n--) {
        int num; cin >> num;
        if(num == 0) {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << -(pq.top().second) << '\n';
                pq.pop();
            }
        } else {
            int abs_num = abs(num);
            pq.push({-abs_num, -num});
        }
    }

    return 0;
}