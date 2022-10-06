#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n; cin >> m >> n;

    vector< vector<int> > v(m, vector<int>(n, 0)); // 원본
    vector< vector<int> > v1(m, vector<int>(n, 0)); // 중복제거
    vector< vector<int> > v2(m, vector<int>(n, 0)); // 압축

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int num; cin >> num;
            v[i][j] = num;
            v1[i][j] = num;
        }
    }

    for(int i = 0; i < m; ++i) {
        sort(v1[i].begin(), v1[i].end());
        v1[i].erase(unique(v1[i].begin(), v1[i].end()), v1[i].end());
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            v2[i][j] = lower_bound(v1[i].begin(), v1[i].end(), v[i][j]) - v1[i].begin();
        }
    }
    
    int cnt = 0;
    // 이중 for문 돌면서 같은거 찾기
    for(int i = 0; i < (m - 1); ++i) {
        for(int j = i + 1; j < m; ++j) {
            if (v2[i] == v2[j]) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}