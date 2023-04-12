#include <bits/stdc++.h>
#define ll long long
#define pcc pair<char, char>

using namespace std;

map<char, pcc> m;

void preorder(char root) {
    if(root == '.') return;
    cout << root;
    preorder(m[root].first);
    preorder(m[root].second);
}

void inorder(char root) {
    if(root == '.') return;
    inorder(m[root].first);
    cout << root;
    inorder(m[root].second);
}

void postorder(char root) {
    if(root == '.') return;
    postorder(m[root].first);
    postorder(m[root].second);
    cout << root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        char root, left, right;
        cin >> root >> left >> right;
        m[root] = {left, right};
    }

    // 전위순회 ABDCEFG 
    // (루트) (왼쪽 자식) (오른쪽 자식)
    preorder('A'); // 현재 root
    cout << '\n';

    // 중위순회 DBAECFG 
    // (왼쪽 자식) (루트) (오른쪽 자식)
    inorder('A');
    cout << '\n';

    // 후위순회 DBEGFCA 
    // (왼쪽 자식) (오른쪽 자식) (루트)
    postorder('A');
    cout << '\n';
    
    return 0;
}