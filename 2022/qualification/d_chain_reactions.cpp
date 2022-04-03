#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		vector<ll> F(N);
		vector<vi> c(N);
		for(ll &x : F) cin >> x;
		for(int i = 0; i < N; ++i) {
			int p; cin >> p;
			if(p) c[p-1].push_back(i);
		}
		ll ans = 0;
		for(int i = N-1; i >= 0; --i) {
			if(c[i].empty()) ans += F[i];
			else {
				ll m = 1e10;
				for(int j : c[i]) m = min(m, F[j]);
				F[i] = max(F[i], m);
				ans += F[i] - m;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}