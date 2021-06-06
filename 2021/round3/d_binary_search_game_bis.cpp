#include <iostream>
#include <vector>
#include <map>
#include "../CPHeaders/mod_arith.h"

using namespace std;
typedef vector<int> vi;
const int MOD = 1e9+7;
typedef mint<MOD> mi;
typedef map<int, int> mii;
const int MN = 34;

mi fact[MN], ifact[MN], bern[MN];
mi C(int n, int k) {
	return fact[n] * ifact[k] * ifact[n-k];
}

int N, M, L;
int A[MN], val[MN];

pair<mii, mii> ways(int l, int i) {
	pair<mii, mii> ans;
	if(l == L) {
		if(val[A[i]] == 0) ans.first[0] = 1;
		else if(val[A[i]] == 1) ans.second[0] = 1;
		else ans.first[0] = ans.second[1] = 1;
	} else {
		pair<mii, mii> a = ways(l+1, 2*i);
		pair<mii, mii> b = ways(l+1, 2*i+1);
		for(const auto &[ta, wa] : a.first)
			for(const auto &[tb, wb] : b.first)
				ans.first[ta+tb] += wa * wb;
		for(const auto &[ta, wa] : a.second)
			for(const auto &[tb, wb] : b.second)
				ans.second[ta+tb] += wa * wb;
		if(l&1) { // min
			for(const auto &[ta, wa] : a.first)
				for(const auto &[tb, wb] : b.second)
					ans.first[ta+tb] += wa * wb;
			for(const auto &[ta, wa] : a.second)
				for(const auto &[tb, wb] : b.first)
					ans.first[ta+tb] += wa * wb;
		} else { // max
			for(const auto &[ta, wa] : a.first)
				for(const auto &[tb, wb] : b.second)
					ans.second[ta+tb] += wa * wb;
			for(const auto &[ta, wa] : a.second)
				for(const auto &[tb, wb] : b.first)
					ans.second[ta+tb] += wa * wb;
		}
	}
	return ans;
}

mi sum(mi n, int p) {
	if(p == 0) return n+1;
	mi ans = pow(n, p+1) / (p+1) + pow(n, p) / 2;
	for(int k = 2; k <= p; ++k)
		ans += bern[k] * fact[p] * ifact[k] * ifact[p-k+1] * pow(n, p-k+1);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0] = ifact[0] = bern[0] = 1;
	for(int i = 1; i < MN; ++i) {
		fact[i] = i * fact[i-1];
		ifact[i] = inv(fact[i]);
		bern[i] = 1;
		for(int j = 0; j < i; ++j)
			bern[i] -= C(i, j) * bern[j] / (i - j + 1);
	}

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> N >> M >> L;
		for(int i = 0; i < (1 << L); ++i) {
			cin >> A[i];
			-- A[i];
		}

		vi cntA(N, 0);
		for(int x : A) ++cntA[x];
		vi c2;
		int zero = 0;
		for(int i = 0; i < N; ++i)
			if(cntA[i] >= 2) c2.push_back(i);
			else {
				val[i] = -1;
				if(cntA[i] == 0) ++ zero;
			}
		int n = c2.size();

		vi wt(N+1, 0);
		for(int S = 0; S < (1 << n); ++S) {
			int t0 = 0;
			for(int i = 0; i < n; ++i) {
				val[c2[i]] = (S >> i) & 1;
				if((S >> i) & 1) ++ t0;
			}
			for(const auto &[t, w] : ways(0, 0).second) wt[t0+t] += w;
		}
		mi ans = 0;
		for(int t = N; t > 0; --t) {
			for(int z = 1; z <= zero; ++z) if(t > z)
				wt[t] += (int) (wt[t-z] * C(zero, z));
			for(int i = 0; i <= t; ++i)
				ans += wt[t] * C(t, i) * pow(mi(M), i) * sum(M-1, N-i) * pow(mi(-1), t-i);
		}

		cout << ans << '\n';
	}

	return 0;
}