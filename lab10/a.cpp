#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main (){
    int n, m;
    cin >> n >> m;

    vector <vector <int>> a(n, vector<int> (m));
    queue <pair<int, int >> q;
    int mr = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            if (a[i][j] == 2){
                q.push(make_pair(i, j));
            }
            else if (a[i][j] == 1){
                mr++;
            }
        }
    }

    int cnt = 0;
    while(!q.empty()){
        if (mr == 0){
            break;
        }
        bool b = false;

        int mario = q.size();
        while(mario--){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i - 1 >= 0 && a[i - 1][j] == 1) {
                b = true;
                a[i - 1][j] = 2;
                q.push(make_pair(i - 1, j));
                mr--;
            }
            if (i + 1 < n && a[i + 1][j] == 1) {
                b = true;
                a[i + 1][j] = 2;
                q.push(make_pair(i + 1, j));
                mr--;
            }
            if (j - 1 >= 0 && a[i][j - 1] == 1) {
                b = true;
                a[i][j - 1] = 2;
                q.push(make_pair(i, j - 1));
                mr--;
            }
            if (j + 1 < m && a[i][j + 1] == 1) {
                b = true;
                a[i][j + 1] = 2;
                q.push(make_pair(i, j + 1));
                mr--;
            }
        }
        if(b){
            cnt++;
        }
    }

    if (mr == 0)cout << cnt;
    else cout << -1;
}