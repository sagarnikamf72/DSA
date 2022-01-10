/**
	DP
**/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<vector<long long int> > dp(n, vector<long long int>(n, 0));
	for(int sz = 2; sz <= n; sz++) {
		for(int i = 0; i + sz - 1 < n; i++) {
			int j = i + sz - 1;
			dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + v[j] - v[i];
		}
	}
	cout << dp[0][n-1] << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
