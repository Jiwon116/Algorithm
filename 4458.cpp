#include <iostream>
#include <string>

using namespace std;

int main() {

    int n;

    cin >> n; 
    
    string s; 
    getline(cin, s);

    while(n--) {
        getline(cin, s);
            
        if ('a' <= s[0] && s[0] <= 'z') {
            s[0] = s[0] - 'a' + 'A';
        }

        cout << s << '\n';        
    }

    return 0;
}