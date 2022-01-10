/**
	Maths
	Ad-hoc
**/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	long long ans = 0;
	for (int i = A; i <= B; i++) {
		long long mn = i + B, mx = i + C;
		long long from = mn <= C ? 0 : mn - C, to = mx <= C ? 0 : mx - C;
		long long mpt = D - C + 1;
		if(from >= mpt) {
			ans +=  (to - from + 1) * mpt;
		} else if (to <= mpt) {
			ans += ( (to*(to + 1))/2 - ((from - 1)*from)/2 );
		} else {
			ans += ( (mpt*(mpt + 1))/2 - ((from - 1)*from)/2 );
			ans += ((to - mpt) * mpt);
		}
	}
	cout << ans << endl;
	return 0;
}
