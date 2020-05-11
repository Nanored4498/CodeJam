#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define MAX_S 1000000
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll T, S;
	vector<ll> P(MAX_S), sum(MAX_S), inc(MAX_S), add(MAX_S);
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> S;
		for(int i = 0; i < S; ++i) cin >> P[i];
		sum[0] = P[0];
		for(int i = 1; i < S; ++i) sum[i] = (P[i] + sum[i-1]) % MOD;
		vector<int> stack = {-1};
		ll res = 0;
		for(int i = 0; i < S; ++i) {
			inc[i] = 0;
			int j = stack.back();
			while(j >= 0 && P[j] <= P[i]) {
				stack.pop_back();
				int k = stack.back();
				inc[i] = (inc[i] + inc[j] + (j-k)*((i-j-1)*P[j] - (sum[i-1]-sum[j]))) % MOD;
				j = k;
			}
			if(j >= 0) add[i] = (inc[i] + add[j] + (j+1)*((i-j-1)*P[i] - (sum[i-1]-sum[j]))) % MOD;
			else add[i] = inc[i];
			res = (res + add[i]) % MOD;
			stack.push_back(i);
		}
		cout << "Case #" << t << ": " << res << "\n";
	}

	return 0;
}