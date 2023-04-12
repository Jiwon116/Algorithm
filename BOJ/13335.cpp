#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, w, l; cin >> n >> w >> l; // n : 트럭의 수, w : 다리의 길이, l : 다리의 최대 하중

    queue<int> truck; // 트럭 각각의 무게

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        truck.push(num);
    }

    int sum = 0; // 트럭들의 무게 (l보다 작거나 같아야함)
    int time = 0; // 시작 시간
    queue<pii> q;

    while(true) {
        if(truck.empty() && sum == 0) break;

        // 트럭이 1초에 1칸씩 이동하고 있음
        time++;

        if(!q.empty() && time == q.front().second + w) {
            sum -= q.front().first;
            q.pop();
        }

        if(!truck.empty() && sum + truck.front() <= l) {
            sum += truck.front();
            q.push({truck.front(), time});
            
            truck.pop();
        }

    }

    cout << time << '\n';

    return 0;
}