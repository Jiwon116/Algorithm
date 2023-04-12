#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Rev(string str)
{
    reverse(str.begin(), str.end());
    int result = stoi(str);
    return result;
}


int main()
{
    string x, y;
    cin >> x >> y;
    int res = Rev(x) + Rev(y);
    cout << Rev(to_string(res)) << endl;

    return 0;
}