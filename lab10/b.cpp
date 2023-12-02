#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int v1, v2;
    cin >> v1 >> v2;

    if (v1 == v2) {
        cout << 0;
        return 0;
    }

    set<int> visited;
    queue<int> ver;
    vector<pair<int, int>> path;

    int cnt = 0;
    ver.push(v1);
    path.push_back(make_pair(v1, 0));
    visited.insert(v1);

    cnt++;
    for (int j = 0; j < n; j++) {
        if (a[v1 - 1][j] == 1) {
            ver.push(j + 1);
            path.push_back(make_pair(j + 1, cnt));
        }
    }
    ver.pop();
    while (!ver.empty()) {
        cnt++;
        int i = ver.front();
        for (int j = 0; j < n; j++) {
            if (!visited.count(j + 1)){
                if (a[i - 1][j] == 1){
                    
                    ver.push(j + 1);
                    path.push_back(make_pair(j + 1, cnt));
                    
                }
            }
        }
        visited.insert(ver.front());
        ver.pop();
    }
    bool found = false;
    for (int i = 0; i < path.size(); i++) {
        if (path[i].first == v2) {
            cout << path[i].second;    
            found = true;
            break; 
            
        }
    }

    if (!found) {
        cout << -1;
    }
    return 0;
}
