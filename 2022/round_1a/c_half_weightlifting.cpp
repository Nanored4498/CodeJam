#include <iostream>
#include <vector>
#include <array>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vi> st(1);
	vector<array<int,3>> c(1, {0,0,0});
	vi S[4][4][4];
	S[0][0][0].push_back(0);
	for(int i = 0; i < st.size(); ++i) {
		for(int j = 0; j < 3; ++j) if(c[i][j] < 3) {
			st.push_back(st[i]);
			st.back().push_back(j);
			array<int, 3> cc = c[i];
			++ cc[j];
			c.push_back(cc);
			S[cc[0]][cc[1]][cc[2]].push_back(st.size()-1);
		}
	}
	int ST = st.size();
	cerr << ST << endl;

	vector<vi> D(st.size(), vi(st.size()));
	for(int i = 0; i < D.size(); ++i) for(int j = 0; j < D.size(); ++j) {
		int k = 0;
		while(k < st[i].size() && k < st[j].size() && st[i][k] == st[j][k]) ++k;
		D[i][j] = st[i].size() + st[j].size() - 2*k;
	}

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int E, W;
		cin >> E >> W;
		vector<vi> X(E, vi(3, 0));
		for(vi &x : X) for(int i = 0; i < W; ++i) cin >> x[i];
		vector<vi> dp(E);
		for(int s : S[X[E-1][0]][X[E-1][1]][X[E-1][2]]) dp[E-1].push_back(D[s][0]);
		for(int i = E-2; i >= 0; --i) {
			for(int s : S[X[i][0]][X[i][1]][X[i][2]]) {
				int d = 1e8;
				for(int j = 0; j < dp[i+1].size(); ++j)
					d = min(d, dp[i+1][j] + D[s][S[X[i+1][0]][X[i+1][1]][X[i+1][2]][j]]);
				dp[i].push_back(d);
			}
		}
		int ans = 1e8;
		for(int d : dp[0]) ans = min(ans, d);
		ans += X[0][0] + X[0][1] + X[0][2];
		cout << ans << '\n';
	}

	return 0;
}