#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int t, n;
    string s;
    
    cin >> t;
    while (getline(cin, s)) {
        if (s.length() == 0) continue;

        int sum = 0;
        stringstream ss(s);
        while (ss >> n) sum += n;
        cout << sum << "\n";
    }

/*    
    while (t--) {
        // 1. 각 수가 무엇인지?
        // 2. String tokenizer를 사용한다.
        // 3. sstream 사용

        int sum = 0;
        getline(cin, s);
        getline(cin, s);

        stringstream stream;
        stream.str(s);
        while(stream >> n) {
            sum += n;
        }

        cout << sum << '\n';
    }
*/
    return 0;
}