#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, s;
vector<int> v;
int ans;

// index는 현재 선택하는 숫자의 인덱스
// cnt는 더한 값들의 합 -> 이게 s가 되면 정답 개수에 추가
void dp(int index, int cnt) {
    if(index == n) return;  // index의 값이 n이면 -> 다 돈거임
    if(cnt + v[index] == s) ans++;  // 현재 선택할 숫자가 더해진 값이 s라면 부분 수열 연산 끝

    dp(index + 1, cnt); // 선택 안함
    dp(index + 1, cnt + v[index]);  // 선택함
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> s;

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    dp(0, 0); // 처음부터 시작

    cout << ans << '\n';
    
    return 0;
}