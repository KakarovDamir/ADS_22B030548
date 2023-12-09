#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int inf = 1e9;

int n, m;
vector<pair<int, pii>> edges;
int par[N], sz[N];

void make_set() {
    for (int i = 1; i <= m; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int a) {
    if (a == par[a])
        return a;
    int pa = find(par[a]);
    par[a] = pa;
    return pa;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (sz[b] > sz[a])
        swap(a, b);
    // merge b to a
    par[b] = a;
    sz[a] += sz[b];
}

int main() {
    cin >> n >>m;
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    make_set();
    sort(edges.begin(), edges.end());
    vector<pii> mst;
    int mst_sum = 0;
    for (const auto& edge : edges) {
        int w = edge.first;
        pii e = edge.second;
        // w - weight of edge
        // e - pair of vertices edge connects
        if (find(e.first) != find(e.second)) {
            mst.push_back(e);
            mst_sum += w;
            unite(e.first, e.second);
        }
    }
    cout << mst_sum << "\n";
    for (const auto& edge : mst) {
        cout << edge.first << ' ' << edge.second << "\n";
    }

    return 0;
}
