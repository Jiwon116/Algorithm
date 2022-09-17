#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;
    list<char> l;
    for(auto e : s) l.push_back(e);

    int n; cin >> n;
    list<char>::iterator iter = l.end();

    while(n--) {
        char command, word;
        cin >> command;
        
        if(command == 'P') {
            cin >> word;
            l.insert(iter, word);
        } 
        else if (command == 'L') {
            if(iter != l.begin()) iter--;
        }
        else if(command == 'D') {
            if(iter != l.end()) iter++;
        }
        else if (command == 'B') {
            if(iter != l.begin()) {
                iter--;
                iter = l.erase(iter);
            }
        }
    }

    for(auto e : l) cout << e; cout << '\n';
    
    return 0;
}