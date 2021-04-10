#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int M;
		cin >> M;
		vector<ll> N(M), P(M);
		ll sum = 0;
		for(int i = 0; i < M; ++i) {
			cin >> P[i] >> N[i];
			sum += P[i] * N[i];
		}
		ll ans = 0;
		ll ms = max(2., sum - 500. * (log(sum) / log(500) + 1.));
		for(ll s = sum; s >= ms; --s) {
			ll pr = s, su = sum;
			bool good = true;
			for(int i = 0; i < M; ++i) {
				ll n = 0;
				while(pr % P[i] == 0) {
					pr /= P[i];
					++ n;
				}
				if(n > N[i]) {
					good = false;
					break;
				}
				su -= n * P[i];
			}
			if(good && pr == 1 && su == s) {
				ans = s;
				break;
			}
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}