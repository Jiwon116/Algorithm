#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    map<string, string> site_pwd;

    // 저장된 사이트와 비번 입력 -> O(nlogn)
    for(int i = 0; i < n; ++i) {
        string site, pwd;
        cin >> site >> pwd;
        // site_pwd.insert(site, pwd);

        site_pwd[site] = pwd;
    }


    
    string f_site;
    for(int i = 0; i < m; ++i) {
        // 찾을 사이트 입력
        cin >> f_site;
        // 해당 사이트 검색 -> O(mlogn)
        cout << site_pwd[f_site] << "\n";
    }

    return 0;
}
// 총 시간 복잡도
// (m + n)logn