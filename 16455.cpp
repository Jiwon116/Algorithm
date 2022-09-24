#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// quickselect
// int kth(std::vector<int> &a, int k) {
//     // pivot을 맨 처음으로 잡기
//     int p = a[(a.size()) / 2];

//     // 3개의 집합 만들기
//     // p보다 작은거 - L
//     // p랑 같은거 - M 
//     // p보다 큰거 - R
//     std::vector<int> L;
//     std::vector<int> M;
//     std::vector<int> R;
//     for(auto &e : a) {
//         if(e < p) L.push_back(e);
//         else if(p < e) R.push_back(e);
//         else M.push_back(e);
//     }

//     // L 크기보다 k가 작다면 k는 L 집합에 속해있음
//     // L + M 크기보다 k가 크다면 k는 R 집합에 속해있음
//     if(k <= L.size()) return kth(L, k);
//     else if ((L.size() + M.size()) < k) return kth(R, k - (L.size() + M.size()));
//     else return p;
// }

// nth_element
int kth(std::vector<int> &a, int k) {
    std::nth_element(a.begin(), a.begin() + k - 1, a.end());

    return a[k-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<int> v;
    while(n--) {
        int num; cin >> num;
        v.push_back(num);
    }

    cout << kth(v, k) << '\n';

    return 0;
}