#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <functional>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N; cin >> N;
		vector<pair<ll,ll>> A(N), B(N+1);
		for(auto &[x, y] : A) cin >> x >> y;
		for(auto &[x, y] : B) cin >> x >> y;
		vector<vector<pair<ll, int>>> d(N);
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j <= N; ++j) {
				ll dx = A[i].first - B[j].first;
				ll dy = A[i].second - B[j].second;
				d[i].emplace_back(dx*dx+dy*dy, j);
			}
			sort(d[i].begin(), d[i].end());
		}
		vector<bool> a(N, true), b(N, true);
		vector<vector<vector<pair<int, int>>>> dp(1<<N, vector<vector<pair<int, int>>>(1<<(N+1)));
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j <= N; ++j) {
				if(d[i][j].first == d[i][0].first) {
					int k = d[i][j].second;
					if(k == 0) continue;
					dp[1<<i][1<<k].emplace_back(i, k);
				}
			}
		}
		for(int pi = 1; pi < (1<<N); ++pi) {
			for(int pj = 1; pj < (1<<(N+1)); ++pj) {
				if(dp[pi][pj].empty()) continue;
				for(int i = 0; i < N; ++i) if(!((pi>>i)&1)) {
					int pi2 = pi|(1<<i);
					int j0 = 0;
					while((pj>>d[i][j0].second)&1) ++j0;
					ll l = d[i][j0].first;
					for(int j1 = j0; j1 <= N; ++j1) if(d[i][j1].first == l) {
						int j = d[i][j1].second;
						if(j == 0) continue;
						if((pj>>j)&1) continue;
						int pj2 = pj|(1<<j);
						if(!dp[pi2][pj2].empty()) continue;
						dp[pi2][pj2] = dp[pi][pj];
						dp[pi2][pj2].emplace_back(i, j);
					};
				}
			}
		}
		if(dp[(1<<N)-1][(1<<(N+1))-2].empty()) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << "POSSIBLE\n";
			for(auto [i, j] : dp[(1<<N)-1][(1<<(N+1))-2]) cout << i+1 << ' ' << j+1 << '\n';
		}
	}

	return 0;
}