#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":";
		int in[12];
		for(int &x : in) cin >> x;
		int ans[4];
		int tot = 1e6;
		for(int i = 0; i < 4; ++i) {
			ans[i] = min(tot, min(in[i], min(in[4+i], in[8+i])));
			tot -= ans[i];
		}
		if(tot) cout << " IMPOSSIBLE";
		else for(int x : ans) cout << ' ' << x;
		cout << '\n';
	}

	return 0;
}