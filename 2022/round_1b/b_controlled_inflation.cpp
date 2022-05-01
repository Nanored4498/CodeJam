#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, P; cin >> N >> P;
		vector<ll> mi(N, 1e9), ma(N, 0);
		for(int i = 0; i < N; ++i) {
			for(int p = P; p--;) {
				ll x; cin >> x;
				mi[i] = min(mi[i], x);
				ma[i] = max(ma[i], x);
			}
		}
		ll d0=2*ma[0]-mi[0], d1=ma[0];
		for(int i = 1; i < N; ++i) {
			ll d2 = ma[i]-mi[i]+min(abs(ma[i]-mi[i-1])+d0, abs(ma[i]-ma[i-1])+d1);
			ll d3 = ma[i]-mi[i]+min(abs(mi[i]-mi[i-1])+d0, abs(mi[i]-ma[i-1])+d1);
			d0 = d2;
			d1 = d3;
		}
		cout << "Case #" << t << ": " << min(d0, d1) << '\n';
	}

	return 0;
}