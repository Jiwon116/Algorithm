#include <iostream>
#include <deque>

using namespace std;

int main() {

    int n; cin >> n;
    deque< pair<int, int> > dq;

    for(int i = 1; i <= n; ++i) {
        int num; cin >> num;
        dq.push_back({i, num});
    }

    while (!dq.empty()) {
        // 무조건 맨 앞에 출력하고
        // 그 다음부터 해당 숫자만큼 이동하기
        int index = dq.front().first; // 풍선의 위치 (첫번째, 두번째 등등)
        cout << index << " ";

        int dq_num = dq.front().second; // 풍선 안에 들어있는 숫자 (3, -1 등등)
        dq.pop_front(); // 풍선 터트림

        // 양수면 오른쪽으로, 음수면 왼쪽으로 이동하기
        if(dq_num > 0) {
            while(dq_num != 1) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            --dq_num;
        } else {
            while (dq_num != -1) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ++dq_num;
        }
    }

    return 0;
}