#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
vector< vector<int> > answer;

void backtrack(vector<int> perm) {
    if(perm.size() == m) {
        answer.push_back(perm);
        return;
    }

    for(int i = 1; i <= n; ++i) {
        bool pass = false;
        
        for(auto e : perm) {
            if(e >= i) {
                pass = true;
                break;
            }
        }

        if(pass) continue;

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

// #include <bits/stdc++.h>
// #define ll long long
// #define pii pair<int, int>

// using namespace std;

// // 조합
// // n개 중에서 m개를 뽑는다
// // 1. 1부터 n이 담긴 벡터 생성
// // 2. m개의 1이 담긴 벡터 생성
// // 3. 위의 벡터에 n - m개의 0 추가
// // 4. 정렬
// // 5. 순열
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
    
//     int n, m; cin >> n >> m;
    
//     vector<int> v1;
//     for(int i = 1; i <= n; ++i) v1.push_back(i);

//     vector<int> v2;
//     for(int i = 0; i < m; ++i) v2.push_back(0);
//     for(int i = 0; i < n - m; ++i) v2.push_back(1);

//     sort(v2.begin(), v2.end());

//     vector<int> ans;

//     do {
//         for(int i = 0; i < n; ++i) {
//             if(v2[i] == 0) cout << v1[i] << " ";
//         }
//         cout << '\n';
//     } while (next_permutation(v2.begin(), v2.end()));
    
//     return 0;
// }

