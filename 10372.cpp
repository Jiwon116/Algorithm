#include <iostream>

using namespace std;

int main() {
    
    int clock[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int hh = 0, mm = 0;
    int n; cin >> n;
    while (hh < 24) {
        int answer = 0;

        // h -> hh  
        answer = clock[hh / 10] + clock[hh % 10];
        answer += clock[mm / 10] + clock[mm % 10];

        if (answer == n) {
            cout << hh / 10 << hh % 10 << ":" << mm /10 << mm%10 << "\n";
            return 0;
        }

        ++mm;
        if (mm == 60) {
            ++hh;
            mm = 0;
        }
    }

    cout << "Impossible\n";


    return 0;
}