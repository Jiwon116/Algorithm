#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    while (getline(cin, s)) {
        int upper_cnt = 0,lower_cnt = 0, number_cnt = 0, space_cnt = 0;

        for(int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                upper_cnt++;
            }

            if (s[i] >= 'a' && s[i] <= 'z') {
                lower_cnt++;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                number_cnt++; 
            }

            if (s[i] == ' ') {
                space_cnt++;
            }

        }
        cout << lower_cnt << " " << upper_cnt << " " << number_cnt << " " << space_cnt << "\n";
    }

    return 0;
}