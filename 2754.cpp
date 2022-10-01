#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    char grade, opt;
    cin >> grade >> opt;

    if (grade == 'F') cout << "0.0\n";
    else {
        int a = 4 - (grade - 'A');
        string b = "";
        if (opt == '+') b = ".3";
        else if (opt == '0') b = ".0";
        else {
            a -= 1;
            b = ".7";
        }

        cout << a << b << "\n";
    }


    return 0;
}