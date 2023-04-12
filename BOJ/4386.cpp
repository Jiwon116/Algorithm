#include <bits/stdc++.h>
#define ll long long
#define pdd pair<double, double>

// 최소 스패닝 트리 - 크루스칼

using namespace std;

int n;
vector<pdd> graph;
vector< pair<double, pdd> > v;
int parent[101];
double answer;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    for(int i = 0; i < n; ++i) parent[i] = i;

    for(int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        graph.push_back({x, y});
    }

    // 두 점 사이의 거리 계산
    for(int i = 0; i < graph.size(); ++i) {
        for(int j = i + 1; j < graph.size(); ++j) {
            double dist_cost = dist(graph[i].first, graph[i].second, graph[j].first, graph[j].second);
            v.push_back({dist_cost, {i, j}});
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); ++i) {
        int a = find(v[i].second.first);
        int b = find(v[i].second.second);

        if(a != b) {
            parent[a] = b;
            answer += v[i].first;
        }
    }

    cout.precision(3);
    cout << answer << '\n';
    
    return 0;
}