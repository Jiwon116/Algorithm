#include <iostream>

using namespace std;

int count = 0; // 0의 개수 세는 변수

// 팩토리얼 구하는 함수
long long factorial(int n) {
    long long result = 1;

    if (n == 0) result = 0;
    else if (n == 1) result = 1; // 1이면 1 리턴
    else {
        // 1이 아니면 5 * 4! 이런식으로 계산한 값 리턴
        for(int i = 1; i <= n; ++i) {
            result = result * i;

            while (result % 10LL == 0 && result != 0) {
                count++;
                result = result / 10LL;
            }
            
            result %= 10000;
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n; // n 입력받기

    factorial(n);

    cout << count << '\n';

    return 0;
}