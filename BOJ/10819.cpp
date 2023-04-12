#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
vector<int> v;
vector<int> arr;
bool visited[9] = {false, };
int answer = 0;

void brute() {
    if (arr.size() == n) {
        int result = 0;
        for(int i = 0; i < n - 1; i++) result += abs(arr[i + 1] - arr[i]);
        answer = max(answer, result);
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            visited[i] = true;
            arr.push_back(v[i]);
            brute();
            arr.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    brute();

    cout << answer << '\n';
    
    return 0;
}