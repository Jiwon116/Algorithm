#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int count[10001] = {0, };

    while(n--) {
        int num;
        cin >> num;
        
        count[num]++;   // 각 수가 몇개씩 있는지
    }

    for(int i = 0; i < 10001; ++i) {
        for(int j = 0; j < count[i]; ++j) {
            cout << i << "\n";
        }
    }

    return 0;
}


