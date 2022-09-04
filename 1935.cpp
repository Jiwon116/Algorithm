#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s; // 식 입력 (ABC*+DE/-)

    // v[0] = A, v[1] = B ...
    vector<int> v;
    v.resize(26);
    for(int i = 0; i < n; ++i) {
        int m; cin >> m;
        
        v[i] = m;
    }

    stack<double> st;

    // 입력 받은 식에 값을 대입해서 stack에 넣기
    // 만약 s[i]가 연산자라면 stack의 top을 두 번 빼서 연산 진행
    for(int i = 0; i < s.length(); ++i) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            int value = v[s[i] - 'A'];
            st.push(value);
        } else {
            double num1 = st.top(); st.pop();
            double num2 = st.top(); st.pop();

            if (s[i] == '+') st.push(num2 + num1);
            else if (s[i] == '-') st.push(num2 - num1);
            else if (s[i] == '*') st.push(num2 * num1);
            else if (s[i] == '/') st.push(num2 / num1);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';

    return 0;
}