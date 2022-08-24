#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string s;
    cin >> s;
 
    bool isCpp = false, isJava = false, isError = false;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) {
            if (!i || isCpp) {
                isError = true;
                break;
            }

            result += '_';
            result += s[i] - 'A' + 'a';
            isJava = true;
        }
        else if (s[i] == '_') {
            if (!i || isJava || i == s.length() - 1 || s[i + 1] == '_' || isupper(s[i + 1])) {
                isError = true;
                break;
            }
            result += s[i + 1] - 'a' + 'A';
            i++;
            isCpp = true;
        }
        else {
            result += s[i];
        }
    }
 
    if (isError)
        cout << "Error!\n";
    else
        cout << result << '\n';
 
    return 0;
}
