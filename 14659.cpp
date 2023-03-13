#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int arr[30001];
int result = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) break;
            else cnt++;

            result = max(result, cnt);
        }
    }
    
    cout << result << "\n";
    
    return 0;
}