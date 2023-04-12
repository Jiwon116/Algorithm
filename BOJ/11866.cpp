#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    vector<int> v;

    // 1부터 N까지 숫자 집어넣기
    for(int i = 1; i <= n; ++i) q.push(i);

    int count = 1;

    while(!q.empty()) {
        // count가 k라면 큐의 맨 앞에 있는 수 벡터에 담고 제거
        // 아니라면 큐의 맨 앞에 있는 수를 뒤로 옮기기
        if (count == k) {
            v.push_back(q.front());
            q.pop();
            count = 1;
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }

    cout << "<";
    for(int i : v) {
        if (i == v.back()) cout << i;
        else cout << i << ", ";
    }
    cout << ">";

    return 0;
}