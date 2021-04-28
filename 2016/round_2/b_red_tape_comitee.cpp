#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef vector<double> vd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(17);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, K;
		cin >> N >> K;
		vd P(N);
		for(int i = 0; i < N; ++i) cin >> P[i];
		sort(P.begin(), P.end());
		vd P2(P.begin()+N-K, P.end());
		double ans = 0.;																																																							
		for(int i = 0; i <= K; ++i) {
			if(i > 0) P[K-i] = P2[K-i];
			vd dp(K/2+1, 0.), tmp(K/2+1);
			dp[0] = 1.;
			for(int j = 0; j < K; ++j) {
				tmp[0] = (1-P[j]) * dp[0];
				for(int k = 1; k <= K/2; ++k)
					tmp[k] = P[j] * dp[k-1] + (1 - P[j]) * dp[k];
				swap(tmp, dp);
			}
			ans = max(ans, dp[K/2]);
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}