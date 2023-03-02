#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, r, c;
int answer = 0;

void solution(int size, int x, int y) {
    if(x == c && y == r) {
        cout << answer << '\n';
        return;
    }
    
    if (c >= x && r >= y && c < x + size && r < y + size) {
        solution(size / 2, x, y);
        solution(size / 2, x + size / 2, y);
        solution(size / 2, x, y + size / 2);
        solution(size / 2, x + size / 2, y + size / 2);
    } else {
        answer += size * size;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> r >> c;

    solution(pow(2, n), 0, 0);
    
    return 0;
}