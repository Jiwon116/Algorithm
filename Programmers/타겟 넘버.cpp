#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    // 경우의 수 -> 각 노드마다 2가지씩 (더하기, 빼기)
    queue<pair<int,int>> q;
    q.push({0, numbers[0]});
    q.push({0, -numbers[0]});
    
    while(!q.empty()) {
        int hereNumIdx = q.front().first; // 현재 더하고 뺀 숫자의 인덱스
        int hereSum = q.front().second; // 현재 숫자(hereNum) 까지 빼거나 더한 값
        q.pop();
        
        // 맨 마지막 숫자까지 전부 다 돌았으면
        // sum이랑 target이랑 같은지 확인하기
        if (hereNumIdx == numbers.size() - 1) {
            answer += (hereSum == target);
            continue;
        }
        
        int val = numbers[hereNumIdx + 1];
        q.push({hereNumIdx + 1, hereSum + val});
        q.push({hereNumIdx + 1, hereSum - val});
    }
    
    return answer;
}