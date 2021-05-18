#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll N = 1e12;
const ll M = 1e10;

int T, W;
vector<pll> a;

void play(ll p) {
	int i = 0;
	while(a[i].second > p || p >= a[i].second + a[i].first) ++ i;
	ll x = a[i].second, y = p+M, z = a[i].second + a[i].first;
	if(p-x >= M) a.emplace_back(p-x, x);
	if(z-y >= M) a.emplace_back(z-y, y);
	a[i] = a.back();
	a.pop_back();
}

int main() {
	cin >> T >> W;
	while(T--) {
		a.clear();
		a.emplace_back(N, 1);
		while(true) {
			ll p;
			cin >> p;
			if(p == -1) return 0;
			if(p < 0) break;
			play(p);
			sort(a.rbegin(), a.rend());
			if(a[0].first >= 3*M) {
				p = a[0].second + 2*M;
			} else if(a[0].first >= 2*M) {
				if(a.size() < 2 || a[1].first < 2*M) { // ONE
					int c = a.size()-1;
					if(c&1) p = a[0].second;
					else p = a[0].second + M - 1;
				} else if(a.size() >= 3 && a[2].first < 2*M) { // TWO + ...
					p = a.back().second;
				} else { // SEVERAL
					int c = 0, i0;
					ll d = -1;
					for(int i = 0; i < a.size(); ++i) {
						if(a[i].first >= 2*M) {
							ll x = a[i].first - 2*M, y = 3*M - a[i].first;
							ll di = min(x, y);
							if(di > d) {
								d = di;
								i0 = i;
							}
							if(x < y) ++ c;
							else c += 2;
						} else ++ c;
					}
					ll x = a[i0].first - 2*M, y = 3*M - a[i0].first;
					if(x < y) -- c;
					else c -= 2;
					if(c&1) p = a[i0].second;
					else p = a[i0].second + M - 1;
				}
			} else p = a[0].second;
			play(p);
			cout << p << endl;
		}
	}

	return 0;
}