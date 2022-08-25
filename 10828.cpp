#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> st;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (s == "push") {
            int num;
            cin >> num;
            st.push(num);
        } else if (s == "pop") {
            if(st.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << st.top() << '\n';
            st.pop();
        } else if (s == "size") {
            cout << st.size() << '\n';
        } else if (s == "empty") {
            if (st.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (s == "top") {
            if(st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
    }


    return 0;
}