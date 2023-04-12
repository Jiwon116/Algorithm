#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    while (getline(cin, s)) {
        int upper_cnt = 0,lower_cnt = 0, number_cnt = 0, space_cnt = 0;

        for(char c : s) {
            if ('A' <= c && c <= 'Z') {
                upper_cnt++;
            }

            else if (c >= 'a' && c <= 'z') {
                lower_cnt++;
            }

            else if (c >= '0' && c <= '9') {
                number_cnt++; 
            }

            else if (c == ' ') {
                space_cnt++;
            }

        }
        cout << lower_cnt << " " << upper_cnt << " " << number_cnt << " " << space_cnt << "\n";
    }

    return 0;
}