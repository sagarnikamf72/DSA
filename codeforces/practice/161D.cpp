/**
	DFS
	DP
**/

#include<bits/stdc++.h>

using namespace std;

const int mxN = 5 * 1e4 + 7;
vector<vector<int> > adj(mxN);
vector<bool> vis(mxN);
vector<vector<vector<int> > > vertices(mxN);
long long ans;
int n, k;


int getNumberOfNodes(int src, int dist) {
//	cerr << "getNumberOfNodes: " << src << " " << dist << endl;
	if(dist == 0) return 1;
	int answer = 0;
	for(int i = 0; i < (int)vertices[src].size(); i++) {
		if ((int)vertices[src][i].size() > dist)
			answer += vertices[src][i][dist];
	}
	// cerr << answer << endl;
	return answer;
}

void dfs(int src, int parent) {
	vis[src] = true;
// 	cerr << "DFS : " << src << endl;
	for (int i = 0; i < (int)adj[src].size(); i++) {
//		cerr << "CHILD: " << adj[src][i] << endl;
		if (!vis[adj[src][i]]) {
			dfs(adj[src][i], src);
			vector<int> vd(k + 1);
			for(int j = 1; j <= k; j++) { 
				vd[j] = getNumberOfNodes(adj[src][i], j - 1);
			}
			vertices[src].push_back(vd);
		} else {
			vector<int> vd;
			vertices[src].push_back(vd);
		}
	}
//	cerr << "SRC " << src << " before " << ans << endl;
	vector<int> dis(k+1, 0);
	for (int dist = 1; dist < k; dist++) {
		for (int i = 0; i < (int) adj[src].size(); i++) {
			if(adj[src][i] == parent) continue;
			dis[dist] += getNumberOfNodes(adj[src][i], dist - 1);
		}
	}
	
	for(int d1 = 1, d2 = k - 1; d1 <= d2; d1++, d2--) {
		long long int tmp = 0;
		for(int i = 0; i < (int)adj[src].size(); i++) {
			if(adj[src][i] == parent) continue;
			tmp += (getNumberOfNodes(adj[src][i], d1 - 1) * (dis[d2] - getNumberOfNodes(adj[src][i], d2 - 1)));
		}
		if(d1 != d2) ans += tmp;
		else ans += (tmp / 2);
	}
	
	for(int i = 0; i < (int)adj[src].size(); i++) {
		if(adj[src][i] == parent) continue;
		ans += getNumberOfNodes(adj[src][i], k - 1);
	}
	
	/**
	for(int i = 0; i < (int)adj[src].size(); i++) {
		if (adj[src][i] == parent) continue;
		ans += getNumberOfNodes(adj[src][i], k - 1);
		for (int j = i + 1; j < (int)adj[src].size(); j++) {
			if (adj[src][j] == parent) continue;
			for (int dis = 1; dis < k; dis++) {
				ans += (getNumberOfNodes(adj[src][i], dis - 1) * getNumberOfNodes(adj[src][j], k - dis - 1));
			}
		}
	}
	**/
	// cerr << "SRC " << src << " after " << ans << endl;
	return;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << ans << endl;
}

void init() {
	ans = 0;
	for(int i = 0; i < mxN; i++) {
		vis[i] = false;
		adj[i].clear();
		vertices[i].clear();
	}
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) {
		init();
		solve();
	}
	return 0;
}
