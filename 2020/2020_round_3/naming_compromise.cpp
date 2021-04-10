#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		string C, J;
		cin >> C >> J;
		int n = C.size(), m = J.size();
		vector<vi> dp(n+1, vi(m+1));
		for(int i = 0; i <= n; ++i) dp[i][0] = i;
		for(int j = 0; j <= m; ++j) dp[0][j] = j;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
				if(C[i-1] == J[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				else dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);
			}
		}
		int s = dp[n][m] / 2;
		int i = n, j = m;
		string ans = C;
		while(s--) {
			while(i > 0 && j > 0 && C[i-1] == J[j-1]) {
				-- i;
				-- j;
			}
			if(i > 0 && dp[i][j] == 1+dp[i-1][j]) ans[--i] = '-';
			else if(dp[i][j] == 1+dp[i][j-1]) ans.insert(i, 1, J[--j]);
			else ans[--i] = J[--j];
		}
		cout << "Case #" << t << ": ";
		for(char c : ans) if(c != '-') cout << c;
		cout << '\n';
	}

	return 0;
}