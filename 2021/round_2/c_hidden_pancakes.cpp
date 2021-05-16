#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int MAX_N = 1e5+5;

ll fact[MAX_N], ifact[MAX_N];

ll pow(ll x, ll p) {
	ll ans = 1;
	while(p > 0) {
		if(p&1) ans = (ans * x) % MOD;
		p >>= 1;
		x = (x * x) % MOD;
	}
	return ans;
}

ll inv(ll x) {
	return pow(x, MOD-2);
}

ll comb(int k, int n) {
	return (fact[n] * ((ifact[k] * ifact[n-k]) % MOD)) % MOD;
}

vector<int> pos[MAX_N];

ll f(int a, int b, int v) {
	if(a == b) return 1;
	int r = 0, l = pos[v].size()-1;
	if(l == -1) return 0;
	while(r < l) {
		int c = (r+l+1)/2;
		if(pos[v][c] >= b) l = c-1;
		else r = c;
	}
	int p = pos[v][r];
	if(p >= b || p < a) return 0;
	ll x = f(a, p, v), y = f(p+1, b, v+1);
	int k = p-a;
	int n = b-a-1;
	return (comb(k, n) * ((x * y) % MOD)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0] = 1;
	for(int i = 1; i < MAX_N; ++i) fact[i] = (fact[i-1] * i) % MOD;
	for(int i = 0; i < MAX_N; ++i) ifact[i] = inv(fact[i]);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		for(int i = 0; i < N; ++i) {
			int V;
			cin >> V;
			pos[V].push_back(i);
		}
		cout << "Case #" << t << ": " << f(0, N, 1) << '\n';
		for(int i = 0; i < N; ++i) pos[i].clear();
	}

	return 0;
}