#include <iostream>
#include <vector>
#include <algorithm>
#include "../CPHeaders/mod_arith.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MOD = 1e9+7;
typedef mint<MOD> mi;
const int MM = 105;

mi fact[MM], ifact[MM];

mi C(int n, int k) {
	return fact[n] * ifact[k] * ifact[n-k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0] = ifact[0] = 1;
	for(int i = 1; i < MM; ++i) {
		fact[i] = i * fact[i-1];
		ifact[i] = inv(fact[i]);
	}

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N, M, L;
		cin >> N >> M >> L;
		vi A(1<<L), order(N), rank(N), who(1<<L);
		for(int &x : A) {
			cin >> x;
			-- x;
		}
		for(int i = 0; i < N; ++i) order[i] = i;

		mi ans = 0;
		do {
			for(int i = 0; i < N; ++i) rank[order[i]] = i;
			for(int i = 0; i < (1<<L); ++i) who[i] = rank[A[i]];
			for(int l = L; l >= 1; --l) {
				for(int i = 0; i < (1 << (l-1)); ++i)
					if(l&1) who[i] = max(who[2*i], who[2*i+1]);
					else who[i] = min(who[2*i], who[2*i+1]);
			}
			int r = who[0];
			int ce0 = 0;
			int ce1 = 0;
			for(int i = 1; i < N; ++i) if(order[i-1] < order[i]) {
				if(i <= r) ++ ce0;
				else ++ ce1;
			}
			for(int v = 0; v < M; ++v) {
				for(int e0 = 0; e0 <= ce0; ++e0) {
					for(int e1 = 0; e1 <= ce1; ++e1) {
						int inf = r - e0;
						int sup = N-1 - r - e1;
						if(inf > v) continue;
						if(sup > M-v-1) continue;
						ans += (v+1) * C(ce0, e0) * C(ce1, e1) * C(v, inf) * C(M-v-1, sup);
					}
				}
			}
		} while(next_permutation(order.begin(), order.end()));
		cout << ans << '\n';
	}

	return 0;
}