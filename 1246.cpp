#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, m, answer, price = 0;
vector<int> P;
vector<int> total;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int p; cin >> p;
        P.push_back(p);
    }

    sort(P.rbegin(), P.rend()); // 거꾸로 정렬

    for (int i = 0; i < m; ++i) {
        if (i+1 > n) break;
        // 첫번째 방법

        if (answer < P[i] * (i+1)) {
            answer = P[i] * (i+1);
            price = P[i];
        }
    }

    cout << price << " " << answer << "\n";

    // 두번째 방법
    //sort(total.begin(), total.end());
    //cout << total.back() << "\n";

    // 세번째 방법
    //cout << *max_element(total.begin(), total.end()) << "\n";

    return 0;
}