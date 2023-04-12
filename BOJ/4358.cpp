#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 소수점 자리수 고정 및 n번째에서 반올림하기
    cout << fixed;
    cout.precision(4);

    string s;
    map<string, double> m;
    int total_cnt = 0;

    while(getline(cin, s)) {
        if(m.find(s) != m.end()) m[s]++;
        else m[s] = 1;
        total_cnt++;
    }

    for(auto e : m) {
        e.second = (e.second / total_cnt) * 100;
        cout << e.first << " " << e.second << '\n';
    }


    return 0;
}