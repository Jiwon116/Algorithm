#include <iostream>
#include <string>

using namespace std;

// 원이 시계방향(오른쪽에서 왼쪽)으로 이동하면
// 화살표는 반시계방향(왼쪽에서 오른쪽)으로 이동
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    string ans;

    cin >> n >> m;

    // 문자열 '?'로 초기화
    for(int i = 0; i < n; i++) {
        ans.push_back('?');
    }

    int curPos = 0;    // 화살표 위치 (화살표가 가리키고 있는 곳)
    bool flag = true;

    for (int i = 0; i < m; i++) {
        int k;
        char s;
        
        cin >> k >> s;

        k %= n;
        curPos -= k;

        // 계속 원형으로 돌기 때문에 
        // 화살표 위치가 음수면 n만큼 더해주기
        if (curPos < 0) {
            curPos += n;
        }

        // 화살표가 가리킨 곳이 '?'이 아님 -> 이미 다른 문자가 있음
        // 그 문자가 입력받은 문자랑 다름
        if(ans[curPos] != '?' && ans[curPos] != s) {
            cout << "!" << '\n';
            flag = false;
            break;
        }

        // 입력받은 문자가 이미 있음 -> 같은 문자열 중복
        if(ans.find(s) != string::npos && ans[curPos] != s) {
            cout << "!" << '\n';
            flag = false;
            break;
        }

        ans[curPos] = s;
        
    }
    
    for (int i = 0; flag && i < n; ++i) {
        cout << ans[(curPos + i) % n];
    }

    return 0;
}