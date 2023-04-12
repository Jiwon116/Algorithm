/*
// 첫번째 방법 - '-'으로 단어 쪼갠 후 대문자 출력
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define MAX 101

using namespace std;

vector<string> split(string str, char del) {
    istringstream iss(str);

    string buffer;
    vector<string> result;

    while(getline(iss, buffer, del)) {
        result.push_back(buffer);
    }

    return result;
}

int main () {

    string s;
    vector<string> v;

    cin >> s;

    v = split(s, '-');

    for (int i = 0; i < v.size(); i++) {
        cout << v[i][0];
    }

    return 0;
}
*/

// 두번째 방법 - 대문자면 출력
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, answer;

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 65 &&  s[i] <= 90) {
            answer += s[i];
        }
    }

    cout << answer << '\n';
    
    return 0;
}