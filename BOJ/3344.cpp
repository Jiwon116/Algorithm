#include <iostream>
#define MAX 100000

using namespace std;

int n, answer = 0;
bool visited[MAX][MAX];

int dfs(int depth) {
    if (depth == n) {
        answer++;
        return;
    }

    
}

int main() {

    cin >> n;

    // dfs로 하나씩 탐색하면서 가지치기 함 (백트래킹)

}