#include <bits/stdc++.h>

using namespace std;

int arr1[500001];   // 높이가 k인 석순
int arr2[500001];   // 시작 위치가 k인 종유석

int p1[500001]; // 높이가 k 이하인 석순의 개수
int p2[500001]; // 시작 위치가 k 이하인 종유석의 개수

int main() {
    int n, h; cin >> n >> h;

    for(int i = 1; i <= n; ++i) {
        int k; cin >> k;
        if(i % 2 == 0) arr2[h - k + 1]++;
        else arr1[k]++;
    }

    for(int k = 1; k <= h; ++k) {
        p1[k] = p1[k - 1] + arr1[k];
        p2[k] = p2[k - 1] + arr2[k];
    }

    int answer = 1e9, answer_cnt = 0;
    for(int cur = 1; cur <= h; ++cur) {
        int result = p1[h] - p1[cur - 1] + p2[cur];
        // cout << p1[h] << " - " << p1[cur - 1] << " + " << p2[cur] << "\n";
        // cout << "cur(" << cur << ") : " << result << "\n";
        if (answer > result) {
            answer_cnt = 1;
            answer = result;
        } else if (answer == result) {
            ++answer_cnt;
        }
    }

    cout << answer << " " << answer_cnt << '\n';

    return 0;
}