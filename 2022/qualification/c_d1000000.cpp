#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		vector<int> S(N);
		for(int &x : S) cin >> x;
		sort(S.rbegin(), S.rend());
		int ans = N;
		for(int i = 0; i < ans; ++i)
			ans = min(ans, i+S[i]);
		cout << ans << '\n';
	}

	return 0;
}