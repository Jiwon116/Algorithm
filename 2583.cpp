#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int m, n, k;
int board[101][101];
bool vis[101][101] = {false, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> m >> n >> k;

    for(int i = 0; i < k; ++k) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        for(int b = y1; b < y2; ++b) {
            for(int a = x1; a < x2; ++a) {
                // if(vis[a][b]) continue;
                vis[a][b] = true;
            }
        }

        

    }
    
    return 0;
}