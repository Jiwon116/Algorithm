#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
vector<int> graph[1000001];
int arr[1000001][2];
bool visited[1000001];

void dp(int index) {
    arr[index][1] = 1;
    visited[index] = true;

    for(int i = 0; i < graph[index].size(); ++i) {
        int next = graph[index][i];

        if(visited[next]) continue;

        dp(next);
        arr[index][0] += arr[next][1];
        arr[index][1] += min(arr[next][1], arr[next][0]);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, false, sizeof(visited));
    
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    dp(1);

    cout << min(arr[1][0], arr[1][1]) << '\n';
    
    return 0;
}