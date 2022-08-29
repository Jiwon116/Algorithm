#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;   // 총 개수 입력받기

    // 만들어야 하는 수열 입력받기
    // 4 3 6 8 7 5 2 1
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int j = 0; // 확인할 벡터의 인덱스
    stack<int> st;
    string ans;

    for(int i = 1; i <=n; ++i) {
        st.push(i);
        ans += "+";
        while (!st.empty() && st.top() == v[j]) {
            st.pop();
            ans += "-";
            ++j;
        }
    }

    if (!st.empty()) cout << "NO\n";
    else {
        for(char s : ans) cout << s << "\n";
    }
    
    return 0;
}
