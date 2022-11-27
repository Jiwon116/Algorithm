#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

struct STUDENT{
    string name;
    int kor, eng, math;
};

bool cmp(STUDENT a, STUDENT b) {
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
    if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
    if (a.kor == b.kor) return a.eng < b.eng;
    return a.kor > b.kor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;
 
    vector<STUDENT> v;
    v.resize(n + 1);

    for (int i = 0; i < n; ++i){
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
    }

    sort(v.begin(), v.end(), cmp);
 
    for (int i = 0; i < n; ++i) cout << v[i].name << '\n';
    
    return 0;
}