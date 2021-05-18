#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;

void sort_unique(vector<ll> &v) {
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
}

ll pow(ll x, ll p, ll MOD) {
	ll ans = 1;
	while(p > 0) {
		if(p&1) ans = (ans * x) % MOD;
		p >>= 1;
		x = (x * x) % MOD;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, D;
		ll num = 0, den = 0;
		cin >> N >> D;
		vll P(N);
		for(int i = 0; i < N; ++i) {
			ll x, y;
			cin >> x >> y;
			P[i].first = x+y;
			P[i].second = x-y;
		}
		sort(P.begin(), P.end());

		vector<ll> xs, ys; 
		for(const pll &p : P) {
			xs.push_back(p.first-D);
			xs.push_back(p.first+D);
			ys.push_back(p.second-D);
			ys.push_back(p.second+D);
		}
		sort_unique(xs);
		sort_unique(ys);

		unordered_map<ll, vector<tuple<int, int, int>>> info;
		const ll yMul = 9999991;
		const ll MOD = 2000000011;
		const ll roll = 997;
		for(int j = 0; j+1 < ys.size(); ++j) {
			ll y = ys[j] + ys[j+1];
			vi inds;
			for(int k = 0; k < N; ++k)
				if(abs(y - 2*P[k].second) <= 2*D)
					inds.push_back(k);
			ll h = 0;
			int k0 = 0, k1 = 0;
			for(int i = 0; i+1 < xs.size(); ++i) {
				ll x = xs[i] + xs[i+1];
				while(k1 < inds.size() && x >= 2LL*(P[inds[k1]].first-D)) {
					if(k0 < k1) {
						ll hd = MOD + ((P[inds[k1]].first - P[inds[k1-1]].first) + yMul * (P[inds[k1]].second - P[inds[k1-1]].second)) % MOD;
						h = (roll * h + hd) % MOD;
					}
					else h = 0;
					++ k1;
				}
				while(k0 < k1 && x > 2LL*(P[inds[k0]].first+D)) {
					if(k0+1 < k1) {
						ll rp = pow(roll, k1-k0-2, MOD);
						ll hd = MOD + ((P[inds[k0+1]].first - P[inds[k0]].first) + yMul * (P[inds[k0+1]].second - P[inds[k0]].second)) % MOD;
						h = (h + MOD - ((rp * hd) % MOD)) % MOD;
					} else h = 0;
					++ k0;
				}
				if(k0 == k1) continue;
				den += (xs[i+1] - xs[i]) * (ys[j+1] - ys[j]);
				info[h].emplace_back(i, j, inds[k0]);
			}
		}

		for(const auto &[_, rs] : info) {
			vector<pair<ll, int>> rxs;
			rxs.reserve(2*rs.size());
			vll rys(rs.size());
			vector<ll> ys2(2*rs.size());
			for(int i = 0; i < rs.size(); ++i) {
				auto [k, l, m] = rs[i];
				rxs.emplace_back(xs[k] - P[m].first, i);
				rxs.emplace_back(xs[k+1] - P[m].first, -i-1);
				ys2[2*i] = rys[i].first = ys[l] - P[m].second;
				ys2[2*i+1] = rys[i].second = ys[l+1] - P[m].second;
			}
			sort(rxs.begin(), rxs.end());
			sort_unique(ys2);

			int start = 1;
			while(start < ys2.size()-1) start <<= 1;
			vector<ll> y0(2*start), y1(2*start);
			vector<ll> l1(2*start, 0), l2(2*start, 0);
			vi nc(2*start, 0);
			for(int i = 0; i < ys2.size()-1; ++i) {
				y0[start + i] = ys2[i];
				y1[start + i] = ys2[i+1];
			}
			for(int i = start + ys2.size() - 1; i < y0.size(); ++i)
				y0[i] = y1[i] = ys2.back();
			for(int i = start-1; i > 0; --i) {
				y0[i] = y0[2*i];
				y1[i] = y1[2*i+1];
			}

			function<void(ll, ll, int, int)> fadd;
			fadd = [&](ll a, ll b, int i, int add) {
				if(b <= y0[i] || y1[i] <= a) return;
				if(a <= y0[i] && y1[i] <= b) nc[i] += add;
				else {
					fadd(a, b, 2*i, add);
					fadd(a, b, 2*i+1, add);
				}
				if(nc[i] == 0) {
					l1[i] = i < start ? l1[2*i] + l1[2*i+1] : 0;
					l2[i] = i < start ? l2[2*i] + l2[2*i+1] : 0;
				} else if(nc[i] == 1) {
					l1[i] = y1[i] - y0[i];
					l2[i] = i < start ? l1[2*i] + l1[2*i+1] : 0;
				} else {
					l1[i] = y1[i] - y0[i];
					l2[i] = y1[i] - y0[i];
				}
			};

			ll lx = rxs[0].first;
			for(auto &[x, i] : rxs) {
				num += (x - lx) * (l1[1] - l2[1]);
				int a = 1;
				if(i < 0) {
					a = -1;
					i = -i-1;
				}
				fadd(rys[i].first, rys[i].second, 1, a);
				lx = x;
			}
		}
		
		ll g = __gcd(num, den);
		num /= g;
		den /= g;
		cout << "Case #" << t << ": " << num << ' ' << den << '\n';
	}

	return 0;
}