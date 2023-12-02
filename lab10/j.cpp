#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector <bool> visited;
vector <vector <int> > v;


void dfs(int w){
    visited[w] = true;
    
    for(int i = 0; i < v[w].size(); i++){
        if(!visited[v[w][i]]){
            if(v[v[w][i]].size() > v[w].size()){
                cnt++;
            }

            dfs(v[w][i]);
        }
    }
}


int main(){
    cin >> n >> m;
    visited.resize(n);
    v.resize(n);

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        v[x].push_back(y);
    }

    for(int i = 0; i < m; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    cout << cnt + abs(n-m);
}