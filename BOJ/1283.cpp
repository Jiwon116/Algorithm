#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool key[26]; // 해당 글자가 단축기로 지정되어 있는지 확인하는 변수
    memset(key, false, sizeof(key));

    string s;
    getline(cin, s); // 공백 제거

    while(n--) {
        getline(cin, s); // 한줄씩 입력받기
        stringstream ss(s); // 한 단어(공백기준)으로 나눔

        // 한 단어씩 저장하기
        vector<string> words;
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        
        bool has_already_key = false;  // 이미 단축키로 지정되었는지 확인
        
        vector<string> ans; // 정답 저장하기

        // 각 단어들의 첫 글자가 단축키로 지정되어 있는지 확인
        // Save As -> [S]ave As
        // Save All -> Save [A]ll
        for(string w : words) {
            char c = w[0]; // 각 단어들의 첫글자
            if ('A' <= c && c <= 'Z') c = c - 'A' + 'a'; // 만약 대문자라면 소문자로 변경

            // c가 'a'라면, key[c -'a'] = key[0]
            if(!key[c - 'a'] && !has_already_key) {
                key[c - 'a'] = true; // 첫 글자가 단축키로 지정됨
                has_already_key = true;
                string answer;
                answer += w[0];
                ans.push_back("[" + answer + "]" + w.substr(1)); // 단축키로 지정된 첫 글자에 []를 저장해줌
            } else {
                ans.push_back(w); // 첫 글자를 단축키로 자정할 수 없다면 단어 그대로 저장
            }
        }

        // 정답만 출력
        if(has_already_key) {
            for(string w : ans) {
                cout << w << " ";
            }
            cout << '\n';
            continue;
        }

        // 각 단어들의 두번째 글자부터 단축키로 지정되어 있는지 확인
        // Save -> [S]ave
        // Save As -> Save [A]s
        // Save All -> Sa[v]e All
        if (!has_already_key) { // 단축키로 지정되지 않은 단어들만 확인
            for(string word : words) {
                for (char w : word) {  // 단어의 각 글자
                    char c = w;
                    if ('A' <= c && c <= 'Z') c = c - 'A' + 'a'; // 만약 대문자라면 소문자로 변경

                    if(!key[c - 'a'] && !has_already_key) {
                        key[c - 'a'] = true;
                        has_already_key = true;
                        cout << "[" << w << "]";
                    } else {
                        cout << w;
                    }
                }
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}