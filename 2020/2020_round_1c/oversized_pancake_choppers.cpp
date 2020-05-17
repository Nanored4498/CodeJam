#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int T, N, D;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> N >> D;
		vector<LL> A(N);
		for(int i = 0; i < N; ++i) cin >> A[i];
		sort(A.begin(), A.end());
		map<PLL, PII> m;
		for(LL d = 1; d < D; ++d) {
			for(LL a : A) {
				LL g = __gcd(a, d);
				PLL f = {a/g, d/g};
				if(!m.count(f)) m[f] = {0, 0};
				PII &mid = m[f];
				if(mid.first + d <= D) {
					mid.first += d;
					++ mid.second;
				}
			}
		}
		int res = D-1;
		vector<PLL> candidates(50, {400000000000, 1});
		for(const auto &p : m) {
			const PLL &f = p.first;
			int score = D - p.second.second;
			if(f.first * candidates[score].second < candidates[score].first * f.second)
				candidates[score] = f;
		}
		for(int i = 0; i < D-1; ++i) {
			LL num = candidates[i].first, den = candidates[i].second;
			int j = N-1, count=0;
			while(j >= 0 && den*A[j] >= num) {
				count += (den*A[j--]) / num;
				if(count >= D) break;
			}
			if(count >= D) {
				res = i;
				break;
			}
		}
		cout << "Case #" << t << ": " << res << "\n";
	}

	return 0;
}