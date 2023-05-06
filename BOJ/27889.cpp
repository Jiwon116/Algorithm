#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;

    if(s == "NLCS") cout << "North London Collegiate School";
    else if(s == "BHA") cout << "Branksome Hall Asia";
    else if(s == "KIS") cout << "Korea International School";
    else cout << "St. Johnsbury Academy";

    return 0;

}
