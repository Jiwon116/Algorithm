#include <iostream>
#include <cstring>
#include <set>

#define MAX 1001

using namespace std;

int main() {
	
	char s[MAX];
	set<string> result;

	cin >> s;
	
	int str_len = strlen(s);

	for (int i = 1; i <= str_len +1; ++i) {
		for (int j = 0; j < str_len - i + 1; ++j) {
			int start = j;
			int end = i + j;

			string sub_str(s + start, s + end);
			result.insert(sub_str);
		}
	}

	cout << result.size() << endl;

	return 0;
}
