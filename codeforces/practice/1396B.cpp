/**
	Greedy
	Ad-hoc
**/

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	set<int> s;
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x] = mp.find(x) == mp.end() ? 1 : mp[x] + 1;
		s.insert(x);
	}
	int winner = 1; // 0 -> T, 1 -> HL
	int picked = 0;
	while(true) {
		if(s.empty()) break;
		int last = *(--s.end());
		int tmp = last - 1;
		mp[last] = mp[last] - 1;
		if(mp[last] == 0) s.erase((--s.end()));
		if(picked != 0) { mp[picked]++; s.insert(picked); }
		picked = tmp;
		winner = 1 - winner;
	}
	cout << (winner == 0 ? "T" : "HL") << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
