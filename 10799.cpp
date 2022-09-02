#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    stack<char> st;

    cin >> s;

    int answer = 0;

    for(int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') st.push(s[i]); // ( 이면 스택에 넣기

        // ) 가 들어왔는데 바로 직전이 ( 이라면 레이저
        // -> pop 해주고 막대기 개수 (= 스택 크기) 더해주기
        // 바로 직전이 ( 가 아니라면 막대기
        // -> answer에 + 1 더해주기
        else {  
            if (s[i - 1] == '(') {
                st.pop();
                answer += st.size();
            }
            else {
                st.pop();
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}