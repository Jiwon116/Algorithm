#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;
    int board[101][101] = {0, };
    int answer = 0;

    while(n--) {
        int a, b; cin >> a >> b;

        for(int i = b; i < b + 10; ++i) {
            for(int j = a; j < a + 10; ++j) {
                if(!board[i][j]) {
                    answer++;
                    board[i][j] = 1;
                }
            }
        }
    }

    cout << answer << '\n';
    
    return 0;
}