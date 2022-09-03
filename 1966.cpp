#include <iostream>
#include <deque>

using namespace std;

bool fucking_function(deque<pair<int, int>> this_is_not_queue_problem, int imp) {
    for (int i = 1; i < this_is_not_queue_problem.size(); ++i) {
        if (this_is_not_queue_problem[i].first > imp) return true;
    }
    return false;
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        
        int answer = 0;
        
        int n, m;
        cin >> n >> m;

        deque< pair<int, int> > this_is_not_queue_problem;
        int import = 0;

        // 중요도 입력
        for(int i = 0; i < n; ++i) {
            int a; cin >> a;

            if (i == m) import = a; // 내가 확인하고자 하는 문서의 중요도
            this_is_not_queue_problem.push_back({a, i == m ? 1 : 0});
        }

        // 확인하고자 하는 문서보다 중요도가 큰 문서들
        while (true) {
            bool ret = fucking_function(this_is_not_queue_problem, import);
            if (ret == false && this_is_not_queue_problem.front().second == 1) break;

            bool ret2 = fucking_function(this_is_not_queue_problem, this_is_not_queue_problem.front().first);
            if (!ret2) {
                this_is_not_queue_problem.pop_front();
                ++answer;
            } else {
                this_is_not_queue_problem.push_back(this_is_not_queue_problem.front());
                this_is_not_queue_problem.pop_front();
            }
        }

        cout << answer + 1 << '\n';
    }


    return 0;
}