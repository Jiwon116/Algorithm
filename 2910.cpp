#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {

    int n, c; cin >> n >> c;

    vector<int> v;
    map<int, int> cnt, first_index;
    for (int i = 0; i < n; ++i) {
        // 1. 원소를 입력받고 벡터에 삽입
        int x; cin >> x;
        v.push_back(x);

        // 2. count 개수 세기
        cnt[x] += 1;

        // 3. 최초 등장 index 계산
        if (first_index.find(x) == first_index.end())
            first_index[x] = i;
    }

    sort(v.begin(), v.end(), [&] (const int &a, const int &b) {
        if(cnt[a] == cnt[b]) return first_index[a] < first_index[b];
        return cnt[a] > cnt[b];
    });

    for(auto e : v) cout << e << ' '; cout << '\n';

    return 0;
}

