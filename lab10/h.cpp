#include <iostream>
#include <vector>

using namespace std;

void dfs (vector <vector <int> > &a, int i, int j) {
    if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size())
        return;
    if (a[i][j] == 0)
        return;
    if (a[i][j] == 1)
        a[i][j] = 0;
    dfs(a, i - 1, j);
    dfs(a, i + 1, j);
    dfs(a, i, j - 1);
    dfs(a, i, j + 1);
}


int main (){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector <int> (m));
    int i = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0;j < m;j++){
            if (a[i][j] == 1){
                if (a[i][j] == 1){
                    dfs(a, i, j);
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}