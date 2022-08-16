#include <iostream>
#include <string.h>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> vec[MAX];
bool visited[MAX];

void dfs(int x) {
    visited[x] = true;

    for(int there : vec[x]) {
        if(visited[there] == true) continue;

        dfs(there);
    }

}

int main() {

    int n, m = 0;
    
    cin >> n >> m; //정점과 간선 개수

    for(int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    int counter = 0;

    memset(visited, false, sizeof(visited));

    for(int i = 1; i < n+1; ++i){
        if(visited[i] == false) {
            ++counter;
            dfs(i);
        }
    }

    cout << counter << "\n";

    return 0;
}