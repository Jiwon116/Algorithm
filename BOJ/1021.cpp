#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    int answer = 0;

    for(int i = 1; i <= n; ++i) {
        dq.push_back(i);
    }

    // m번 만큼 뽑아내는 수 입력 받기
    while(m--) {
        int num;
        cin >> num; // 뽑아내야 하는 수

        // dq의 맨 앞이 뽑아내야 하는 수라면 그대로 뽑아내기
        if (dq.front() == num) {
            dq.pop_front();
        } else {
            // 그게 아니라면 뽑아내야 하는 수를 맨 앞으로 옮기기
            // 1. 뽑아내야 하는 수의 인덱스 > dq.size / 2 --> 뒤로 이동
            // 2. 뽑아내야 하는 수의 인덱스 <= dq.size / 2 --> 앞으로 이동
            int index = 0;

            for(int i = 0; i < dq.size(); ++i) {
                if (dq[i] == num) {
                    index = i;
                    break;
                }
            }

            if (index > (dq.size() / 2)) {
                while(dq.front() != num) {
                    int dq_back = dq.back();
                    dq.push_front(dq_back);
                    dq.pop_back();
                    answer++;
                }
            } else {
                while(dq.front() != num) {
                    int dq_front = dq.front();
                    dq.push_back(dq_front);
                    dq.pop_front();
                    answer++;
                }
            }
            
            dq.pop_front();
        }
    }

    cout << answer << '\n';

    return 0;
}