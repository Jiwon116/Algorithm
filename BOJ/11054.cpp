#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, answer = 0;
int arr[1001];
int memo1[1001], memo2[1001];

int LIS(int index) {
    if (index == n) return 0;

    int &ret = memo1[index];
    if (ret != -1) return ret;

    ret = 1;

    for (int i = index + 1; i < n; ++i) {
        if (arr[index] > arr[i]) {
            ret = max(ret, LIS(i) + 1);
        }
    }

    return ret;
}

int LDS(int index) {
    if(index == n) return 0;

    int &ret = memo2[index];
    if(ret != -1) return ret;

    ret = 1;

    for(int i = index - 1; i >= 0; --i) {
        if(arr[index] > arr[i]) {
            ret = max(ret, LDS(i) + 1);
        }
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo2));

    cin >> n;
    
    for(int i = 0; i < n; ++i) cin >> arr[i];

    for(int i = 0; i < n; ++i) answer = max(answer, LIS(i) + LDS(i) - 1);
    
    cout << answer << "\n";
}