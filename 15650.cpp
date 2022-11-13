#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

// 조합
// n개 중에서 m개를 뽑는다
// 1. 1부터 n이 담긴 벡터 생성
// 2. m개의 1이 담긴 벡터 생성
// 3. 위의 벡터에 n - m개의 0 추가
// 4. 정렬
// 5. 순열
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    
    vector<int> v1;
    for(int i = 1; i <= n; ++i) v1.push_back(i);

    vector<int> v2;
    for(int i = 0; i < m; ++i) v2.push_back(0);
    for(int i = 0; i < n - m; ++i) v2.push_back(1);

    sort(v2.begin(), v2.end());

    vector<int> ans;

    do {
        for(int i = 0; i < n; ++i) {
            if(v2[i] == 0) cout << v1[i] << " ";
        }
        cout << '\n';
    } while (next_permutation(v2.begin(), v2.end()));
    
    return 0;
}