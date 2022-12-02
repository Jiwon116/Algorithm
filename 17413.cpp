#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

stack<char> st;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    getline(cin, s);

    bool flag = false;

    for(char c : s) {
        if(c == '<') {
            while(!st.empty()) {
                char ch = st.top();
                st.pop();
                cout << ch;
            }

            cout << c;
            flag = true;
            continue;

        } else if (c == '>') {
            cout << c;
            flag = false;
            continue;
        }

        if(flag) {
            cout << c;
        } else {
            if(c == ' ') {
                while(!st.empty()) {
                    char ch = st.top();
                    st.pop();
                    cout << ch;
                }
                cout << c;
            } else {
                st.push(c);
            }
        }
    }

    while(!st.empty()) {
        char ch = st.top();
        st.pop();
        cout << ch;
    }
    
    return 0;
}