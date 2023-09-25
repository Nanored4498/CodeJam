#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <functional>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

ll d2(const pll &a, const pll &b) {
	ll dx = a.first  - b.first;
	ll dy = a.second - b.second;
	return dx*dx+dy*dy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N; cin >> N;
		vector<pll> A(N), B(N+1);
		for(auto &[x, y] : A) cin >> x >> y;
		for(auto &[x, y] : B) cin >> x >> y;
		vector<vector<pair<ll, int>>> d(N);
		vector<vi> G(N);
		for(int i = 0; i < N; ++i) {
			ll l0 = d2(A[i], B[0]);
			for(int j = 1; j <= N; ++j) {
				ll lj = d2(A[i], B[j]);
				if(lj <= l0) G[i].push_back(j);
			}
			sort(G[i].begin(), G[i].end(), [&](int j, int k) { return d2(A[i], B[j]) < d2(A[i], B[k]); });
		}
		
		// Matching
		vi xy(N, -1), yx(N+1, -1), seen(N, -1), pr(N), Q;
		for(int i = 0; i < N; ++i) {
			Q.push_back(i); seen[i] = i;
			while(!Q.empty()) {
				int x = Q.back(); Q.pop_back();
				for(int y : G[x]) {
					if(yx[y] == -1) {
						while(y != -1) {
							yx[y] = x;
							swap(xy[x], y);
							x = pr[x];
						}
						Q.clear();
						break;
					} else if(seen[yx[y]] != i) {
						seen[yx[y]] = i;
						pr[yx[y]] = x;
						Q.push_back(yx[y]);
					}
				}
			}
			if(xy[i] == -1) break;
		}

		if(xy[N-1] == -1) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << "POSSIBLE\n";
			vi ind(N, 0);
			vector<bool> a(N, false), b(N+1, false);
			for(int step = 0; step < N; ++step) {
				bool found = false;
				for(int i = 0; i < N; ++i) if(!a[i] && xy[i] == G[i][ind[i]]) {
					cout << i+1 << ' ' << xy[i]+1 << '\n';
					a[i] = b[xy[i]] = true;
					found = true;
					break;
				}
				if(!found) {
					vector<bool> seen(N, false);
					int i = 0; while(a[i]) ++i;
					while(!seen[i]) {
						seen[i] = true;
						i = yx[G[i][ind[i]]];
					}
					int j = i;
					do {
						xy[j] = G[j][ind[j]];
						swap(j, yx[xy[j]]);
					} while(j != i);
					cout << i+1 << ' ' << xy[i]+1 << '\n';
					a[i] = b[xy[i]] = true;
				}
				for(int i = 0; i < N; ++i) if(!a[i]) {
					while(b[G[i][ind[i]]]) ++ind[i];
				}
			}
		}
	}

	return 0;
}