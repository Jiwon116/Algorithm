#include <bits/stdc++.h>

using namespace std;

bool visited[1000001] = {false, };

// bfs 사용
int solution(int x, int y, int n) {
    int answer = 0;
    
    if(x == y) return 0;
    
    queue<pair<int, int>> q;
    q.push({x, 0});
    visited[x] = true;
    
    while(!q.empty()) {
        int hereX = q.front().first;
        int hereCnt = q.front().second;
        q.pop();
        
        if(hereX == y) {
            answer = hereCnt;
            break;
        }
        
        int val1 = hereX + n;
        if(!visited[val1] && val1 <= y) {
            q.push({val1, hereCnt + 1});
            visited[val1] = true;
        }
        
        int val2 = hereX * 2;
        if(!visited[val2] && val2 <= y) {
            q.push({val2, hereCnt + 1});
            visited[val2] = true;
        }
            
        int val3 = hereX * 3;
        if(!visited[val3] && val3 <= y) {
            q.push({val3, hereCnt + 1});
            visited[val3]= true;
        }
    }
    
    if(answer == 0) answer = -1;
    
    return answer;
    
}