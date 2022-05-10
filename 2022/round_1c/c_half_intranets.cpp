#include <iostream>
#include <vector>

using namespace std;

template <int MOD>
struct mint {
	typedef long long ll;
	static const int mod = MOD;
	int x;
	mint(): x(0) {}
	mint(ll v) {
		x = v % mod;
		if(x < 0) x += mod;
	}

	friend mint pow(mint a, ll p) {
		mint ans = 1;
		for(; p; p >>= 1, a *= a) if(p&1) ans *= a;
		return ans;
	}
	friend mint inv(mint a) { return pow(a, mod-2); }

	explicit operator int() const { return x; }
	friend bool operator==(const mint &a, const mint &b) { return a.x == b.x; }
	friend bool operator!=(const mint &a, const mint &b) { return a.x != b.x; }
	friend bool operator<=(const mint &a, const mint &b) { return a.x <= b.x; }
	friend bool operator<(const mint &a, const mint &b) { return a.x < b.x; }
	friend ostream& operator<<(ostream &stream, const mint &v) { return stream << v.x; }
	friend istream& operator>>(istream &stream, mint &v) { return stream >> v.x; }
	mint& operator+=(const mint &b) { if((x += b.x) >= mod) x -= mod; return *this; }
	mint& operator-=(const mint &b) { if((x -= b.x) < 0) x += mod; return *this; }
	mint& operator*=(const mint &b) { x = (1LL * x * b.x) % mod; return *this; }
	mint& operator/=(const mint &b) { return (*this) *= inv(b); }
	mint& operator%=(const mint &b) { x %= b.x; return *this; }
	mint& operator++() { return (*this) += 1; }
	mint& operator--() { return (*this) -= 1; }
	mint operator-() { return -x; }
	friend mint operator+(mint a, const mint &b) { return a += b; }
	friend mint operator-(mint a, const mint &b) { return a -= b; }
	friend mint operator*(mint a, const mint &b) { return a *= b; }
	friend mint operator/(mint a, const mint &b) { return a /= b; }
};
typedef mint<int(1e9+7)> mi;
typedef vector<mi> vi;

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int M, K; cin >> M >> K;
		int M2 = M/2;
		int E = (M*(M-1))/2;
		vector<vi> dp(M+1, vi(M2+1, 0));
		dp[2][1] = E;
		for(int i = 1; i < E; ++i) {
			vector<vi> dp2(M+1, vi(M2+1, 0));
			for(int s = 2; s <= M; ++s) {
				int s2 = M-s;
				int es = (s*(s-1))/2;
				int es2 = (s2*(s2-1))/2;
				for(int m = 1; m <= M2; ++m) {
					if(s2 > 0) dp2[s+1][m] += (s*s2)*dp[s][m];
					if(i < es) dp2[s][m] += (es-i)*dp[s][m];
					if(s2 > 1) dp2[s+2][m+1] += es2*dp[s][m];
				}
			}
			dp = move(dp2);
		}
		mi den = 0;
		for(int m = 1; m <= M2; ++m) den += dp[M][m];
		cout << dp[M][K]/den << endl;
	}

	return 0;
}