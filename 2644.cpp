#include <iostream>
#include <string.h>
#include <vector>
#define MAX 101

using namespace std;

int n, m;
int a, b;
vector<int> vec[MAX];
bool visited[MAX];
int answer = -1;

void dfs(int x, int counter) {
    visited[x] = true;

    if (x == b) {
        answer = counter;
        return;
    }

    for (int there : vec[x]) {
        if (visited[there] == true) continue;
        dfs(there, counter+1);
    }

}

int main() {
    cin >> n; //전체 사람의 수

    cin >> a >> b; //촌수를 계산해야 하는 두 사람의 번호

    cin >> m; // 부모 자식들 간 관계의 수

    for(int i = 0; i < m; ++i) {
        int from, to = 0;
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    int counter = 0; // 촌수

    memset(visited, false, sizeof(visited));

    dfs(a, counter);

    cout << answer << "\n";

    return 0;
}