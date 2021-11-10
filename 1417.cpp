#include <iostream>
#include <queue>

using namespace std;

int n, m, t, cnt = 0;
priority_queue<int> pq;

int main() {
    // n은 총 입력받는 개수
    // m은 기호 1번 표수
    cin >> n >> m;
    
    // 나머지 후보의 표수
    for(int i = 1; i < n; ++i) {
        cin >> t;
        pq.push(t);
    }

    // queue에 들어있는 크기만큼 돌고
    // queue의 최상위에 있는 값이 m이랑 같거나 크면
    while(pq.size() && pq.top() >= m) {
        // 가장 최상위에 있는 값을 뽑아서
        int vote = pq.top(); pq.pop();
        // 한 표를 빼앗고 다시 집어넣기
        pq.push(vote - 1);
        // 빼앗은 표 카운팅하고
        // m에 빼앗은 표 추가하기
        ++cnt; ++m;
    }

    cout << cnt << "\n";

    return 0;
}