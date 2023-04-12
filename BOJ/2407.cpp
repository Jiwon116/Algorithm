#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
string s[101][101];

string calculate(string a, string b) {
    string answer = "";
    int sum = 0;
    int len = max(a.size(), b.size());

    for(int i = 0; i < len || sum; ++i) {
        if(a.size() > i) sum += a[i] - '0';
        if(b.size() > i) sum += b[i] - '0';

        answer += (sum % 10) + '0';
        sum /= 10;
    }
    return answer;
}

string combi(int x, int y) {
    if(x == y || y == 0) return "1";

    string &res = s[x][y];
    if(res != "") return res;

    res = calculate(combi(x - 1, y - 1), combi(x - 1, y));

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    string ans = combi(n, m);
    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}