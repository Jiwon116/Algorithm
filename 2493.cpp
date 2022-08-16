#include <iostream>
#include <stack>

using namespace std;

int n;
stack<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n; i++) {
        int ele;
        cin >> ele;

        while(!s.empty()) {
            if(s.top().second > ele) {
                cout << s.top().first + 1 << ' ';
                break;
            }

            s.pop();
        }

        if (s.empty()) {
            cout << 0 << ' ';
        }

        s.push(make_pair(i, ele));
    }

    return 0;
}