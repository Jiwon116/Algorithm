#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {

    int t;

    cin >> t;

    for(int i = 1; i <= t; ++i) {
        string s;
        if (i == 1) getline(cin, s);
        getline(cin, s);
        stringstream stream(s);

        string word;
        stack<string> st;
        while (stream >> word) st.push(word);

        cout << "Case #" << i << ": ";

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }

        cout << '\n';
    }

    return 0;
}
