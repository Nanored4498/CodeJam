#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

string d;
int D[10];

void init() {
	for(int i = 0; i < 10; ++i) D[i] = 0;
	for(char c : d) ++ D[c-'0'];
}

void add(ll &x, int i) {
	x = x*10LL + i;
	-- D[i];
}

void fill(ll &a, ll &b, int m) {
	for(int k = 0, i = 0; k < m; ++k) {
		while(D[i] == 0) ++i;
		add(a, i);
	}
	for(int k = 0, i = 9; k < m; ++k) {
		while(D[i] == 0) --i;
		add(b, i);
	}
}

ll test(int X) {
	ll ans = 1e18;
	bool rm = false;
	int D2[10];
	init();
	for(int k = 0; k < 10; ++k) D2[k] = D[k];

	for(int i = 1; i < 10; ++i) while(D2[i] >= (i == X ? 4 : 2)) {
		D2[i] -= 2;
		rm = true;
	}
	if(rm) while(D2[0] >= (0 == X ? 4 : 2)) D2[0] -= 2;

	int count = 0;
	for(int i = 0; i < 10; ++i) count += D2[i];
	if(count == 0) return 0;

	for(int i = rm ? 0 : 1; i < 10; ++i) if(D2[i] > 0) {
		for(int j = i+1; j < 10; ++j) if(D2[j] > 0) {
			for(int k = 0; k < 10; ++k) D[k] = D2[k];
			ll a = 0, b = 0;
			add(a, j);
			add(b, i);
			fill(a, b, (count-2)/2);
			ans = min(ans, a-b);
			break;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> d;
		int n = d.size();
		int m = n/2;
		init();
		if(n&1) {
			ll a = 0, b = 0;
			int i = 1;
			while(D[i] == 0) ++ i;
			add(a, i);
			fill(a, b, m);
			cout << a-b << '\n';
		} else {
			ll ans = 1e18;
			for(int X = 0; X <= 10; ++X)
				ans = min(ans, test(X));
			cout << ans << '\n';
		}
	}

	return 0;
}