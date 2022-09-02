#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;

    for(int i = 0; i < s.length(); ++i) {
        // 알파벳 대문자는 무조건 출력하기
        if ('A' <= s[i] && s[i] <= 'Z') cout << s[i];
        else {
            // 연산자라면 stack에 담고 우선순위 따져서 pop 하기
            if (s[i] == '(') st.push(s[i]);
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop(); // ( 제거
            }
            else if (s[i] == '*' || s[i] == '/') {
                while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-') {
                while(!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}