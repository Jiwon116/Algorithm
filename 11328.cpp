#include <iostream>
#include <string>

using namespace std;

int main() {

    int n;
    string s1, s2;

    cin >> n;

    while(n--) {
        cin >> s1 >> s2;

        int alphabet[26] = {0 ,};
	    bool isPossible = true;

        for (int i = 0; i < s1.length(); i++) {
			alphabet[s1[i] - 'a']++;
			alphabet[s2[i] - 'a']--;
		}
		
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] != 0) {
				isPossible = false;
				break;
			}
		}
		
		if (isPossible) {
			cout << "Possible\n";
		} else {
			cout << "Impossible\n";
		}
    }

    return 0;
}