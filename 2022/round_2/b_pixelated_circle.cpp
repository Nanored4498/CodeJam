#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		ll R; cin >> R;
		ll a = 0;
		set<pair<int,int>> S;
		for(ll x = 1; x <= R; ++x) {
			for(ll r = x+1; r <= R; ++r) {
				ll y = round(sqrt(r*r-x*x));
				if(y <= 0) continue;
				S.emplace(x, y);
				S.emplace(y, x);
			}
			ll y = sqrt(R*R-x*x);
			while(round(sqrt(x*x+(y+1)*(y+1))) <= R) ++y;
			a += y;
		}
		ll b = S.size();
		cout << 4*(a-b) << '\n';
	}

	return 0;
}