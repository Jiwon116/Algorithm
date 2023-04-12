#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
vector< vector<int> > answer;

void backtrack(vector<int> perm) {
    // perm이 m개 만큼 다 뽑았으면
    // answer에 perm을 넣고 종료
    if(perm.size() == m) {
        answer.push_back(perm);
        return;
    }

    for(int i = 1; i <= n; ++i) {
        bool pass = false;

        // perm에 이미 i가 있으면 중복이기 때문에
        // pass를 true로 처리하고 for문 빠져나감 = perm에 추가 안함
        for(auto e : perm) {
            if(e == i) {
                pass = true;
                break;
            }
        }

        if(pass) continue;

        // pass가 false이니 = 중복된 값이 없으니
        // perm에 넣고 재귀함수 호출
        // ex) perm = {5, 2}, i가 1이면 ->  perm{5, 2, 1}
        // m이 3이면 perm을 출력하고 아니면 뒤에 다시 숫자를 넣음
        // for문을 돌아야하기 때문에 perm에 넣은 1 제거
        // 이후 i가 2일때는 중복이라서 넘어가고
        // i 가 3일때 -> perm{5, 2, 3}
        perm.push_back(i);
        backtrack(perm);
        perm.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    vector<int> perm;

    backtrack(perm);

    for(auto e : answer) {
        for(auto ele : e) cout << ele << " ";
        cout << '\n';
    }
    
    return 0;
}