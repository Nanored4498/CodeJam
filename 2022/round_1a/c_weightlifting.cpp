#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int E, W;
		cin >> E >> W;
		vector<vi> dp(E, vi(E));
		vector<vector<vi>> X(E, vector<vi>(E, vi(W)));
		for(int e = 0; e < E; ++e) {
			for(int &x : X[e][e]) cin >> x;
			dp[e][e] = 0;
			for(int x : X[e][e]) dp[e][e] += x;
		}
		for(int l = 1; l < E; ++l) {
			for(int i = 0; i+l < E; ++i) {
				X[i][i+l] = X[i+1][i+l];
				for(int j = 0; j < W; ++j) X[i][i+l][j] = min(X[i][i+l][j], X[i][i][j]);
				dp[i][i+l] = 1e8;
				for(int k = 0; k < l; ++k) dp[i][i+l] = min(dp[i][i+l], dp[i][i+k]+dp[i+k+1][i+l]);
				for(int x : X[i][i+l]) dp[i][i+l] -= x;
			}
		}
		cout << 2*dp[0][E-1] << '\n';
	}

	return 0;
}