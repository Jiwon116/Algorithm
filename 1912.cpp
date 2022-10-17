#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> v;
    vector<int> s;

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    s.push_back(v[0]);

    int answer = v[0];

    for(int i = 1; i < n; ++i) {
        // if(s[i - 1] + v[i] > v[i]) s[i] = s[i - 1] + v[i];

        if(s.back() + v[i] > v[i]) s.push_back(s.back() + v[i]);
        else s.push_back(v[i]);

        answer = max(answer, s.back());
    }

    cout << answer << '\n';

    return 0;
}