// 완전탐색 (브루트포스)
#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int len[MAX];
int total = 0;

int main() {

    for (int i = 0; i < MAX; ++i) {
        cin >> len[i];
        total += len[i];
    }

    sort(len, len + MAX); //오름차순 정렬


    for (int i = 0; i < MAX - 1; ++i) {
        for (int j = i + 1; j < MAX; ++j) {
            if (total - len[i] - len[j] == 100) {
                for (int k = 0; k < MAX; ++k) {
                    if (k != i && k != j) {
                        cout << len[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}
