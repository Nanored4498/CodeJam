#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N, K; cin >> N >> K;
		ll a = 0, b = 0;
		while(N--) {
			ll x; cin >> x;
			a += x;
			b += x*x;
		}
		ll c = (b-a*a)/2;
		if(K == 1) {
			if(a == 0) {
				if(b == 0) cout << 0;
				else cout << "IMPOSSIBLE";
			} else {
				if(c % a == 0) cout << c/a;
				else cout << "IMPOSSIBLE";
			}
		} else {
			ll x = 1-a;
			ll y = c - a*x;
			cout << x << ' ' << y;
		}
		cout << '\n';
	}

	return 0;
}