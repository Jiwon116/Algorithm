#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

    int n;
    string input;
    set<string> s;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> input;

        
    }
    
    // set 활용
    // 어떤 단어가 들어오면 해당 단어로 만들 수 있는 모든 조합을 만들어서 -> O(문자열의 길이^2)
    // set에 넣음 -> O(1)
    // 새로 들어오는 단어가 set에 있는지 없는지를 확인함
    // 총 단어는 n개 들어옴
    // 따라서 최종 O(NL^2)

    return 0;
}