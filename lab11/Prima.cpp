#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int spanningTree(int V, int E, int edges[][3])
{ 
	vector<vector<int>> adj[V];
	
	for (int i = 0; i < E; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		int wt = edges[i][2];
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	vector<bool> visited(V, false);
	
	int res = 0;
	
	pq.push({0, 0});
	
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		
		int wt = p.first;
		int u = p.second; 
		
		if(visited[u] == true){
			continue;
		}
		
		res += wt; 
		visited[u] = true;
		
		for(auto v : adj[u]){
			if(visited[v[0]] == false){
				pq.push({v[1], v[0]}); 
			}
		}
	}
	
	return res; 
}

int main()
{
    int n;
    cin >> n;
	int graph[n][3];
    for (int i = 0;i < n;i++){
        for (int j = 0;j < 3; j++){
            cin >> graph[i][j];
        }
    }

	cout << spanningTree(3, 3, graph) << endl;

	return 0;
}
