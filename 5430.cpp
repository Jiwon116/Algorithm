#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        string p, s;
        int n;
        cin >> p >> n >> s;

        deque<int> dq;
        bool flag = true;

        // 덱에 숫자만 담기
        for(int i = 0; i < s.length(); ++i) {
            string num = "";
            
            while (s[i] != '[' && s[i] != ']' && s[i] != ',') {
                num += s[i];
                ++i;
            }

            if(num.length() != 0) dq.push_back(stoi(num));
        }

        // p에서 D의 개수만큼 pop
        // R의 개수가 짝수면 그대로, 홀수일때만 뒤집기
        int count_r = 0;
        for(int i = 0; i < p.length(); ++i) {
            if(p[i] == 'R') {
                count_r++;
            } else {
                if (dq.empty()) {
                    flag = false;
                    break;
                }
                else {
                    if (count_r % 2 == 0) {
                        dq.pop_front();
                    } else {
                        dq.pop_back();
                    }
                }
                
            }
        }

        // 형식에 맞게 deque 출력
        if(flag) {
            cout << "[";
            if (count_r % 2 == 0) {
                for(int i = 0; i < dq.size(); ++i) {
                    if (i == dq.size() - 1) cout << dq[i];
                    else cout << dq[i] << ",";
                }
            } else {
                for(int i = dq.size() - 1; i >= 0; --i) {
                    if (i == 0) cout << dq[i];
                    else cout << dq[i] << ",";
                }
            }
            cout << "]";
        } else {
            cout << "error";
        }
        

        cout << '\n';

    }


    return 0;
}