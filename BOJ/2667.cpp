#include <iostream>
#include <algorithm> // 정렬을 위해서 사용
#include <string.h>
#include <vector>
#define MAX 30

using namespace std;

int n;
char adj[MAX][MAX];
bool visited[MAX][MAX];
int counter = 0;

vector<int> res;

int movement[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y) {
    visited[x][y] = true;
    counter++;

    for(int i = 0; i < 4; ++i) {
        int thereX = x + movement[i][0];
        int thereY = y + movement[i][1];

        if(adj[thereX][thereY] == '0') continue;

        if(visited[thereX][thereY]) continue;

        dfs(thereX, thereY);
    }
}

int main() {

    int n;
    cin >> n;

    //memset은 숫자 0과 1로만 초기화 가능.
    //문자열로 초기화 하고 싶을 때는 for문이나 fill 함수 사용
    for(int i = 0; i <= n+1; ++i) {
        for(int j = 0; j <= n+1; ++j) {
            adj[i][j] = '0';
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }

    int answer = 0; // 단지의 수
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if (visited[i][j] == true || adj[i][j] == '0') continue;
            counter = 0; // 새로운 단지를 위해 초기화
            dfs(i, j); // 현재 단지에 몇개의 집이 있는지 counter에 저장
            // dfs(i, j) = 좌표 [i, j]에서 시작해 인접한 1들의 총합(집의 수)
            ++answer; // 총 단지의 수 + 1
            res.push_back(counter); //어떤 단지에 속하는 집의 수
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for( int e : res) cout << e << "\n"; // 단지에 포함된 집의 수를 오름차순으로 출력

    return 0;
}