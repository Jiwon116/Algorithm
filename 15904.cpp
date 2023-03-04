#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s, result = "";

	getline(cin, s);

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'U' && result.empty()) {
			result += 'U';
		}
		else if (s[i] == 'C' && result == "U") {
			result += 'C';
		}
		else if (s[i] == 'P' && result == "UC") {
			result += 'P';
		}
		else if (s[i] == 'C' && result == "UCP") {
			result += 'C';
		}
	}


	if (result == "UCPC") cout << "I love UCPC\n";
	else cout << "I hate UCPC\n";
    
    return 0;
}