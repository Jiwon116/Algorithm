#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

vector<int> v[100001];
int parent[100001]; // 부모가 누군지 저장하는 배열
bool visited[100001] = {false, }; // 양방향이기 때문에 방문했는지 체크

void tree(int cur) {
    for(auto e : v[cur]) {
        if(visited[e]) continue;

        parent[e] = cur; // e의 부모는 cur이다
        visited[e] = true;
        tree(e);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        int first, second; cin >> first >> second;
        // v[1] = {4, 6}
        v[first].push_back(second);
        v[second].push_back(first); // 양방향이기 때문에 같이 저장해줘야 함
    }

    tree(1);
    
    for(int i = 2; i <= n; ++i) {
        cout << parent[i] << '\n';
    }

    return 0;
}