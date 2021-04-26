#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<double> vd;

int T, N, B;
vd dp, p10(17, 1.);

double f(int a, int b, int c, int d);

pair<int, double> best_move(int a, int b, int c, int d, double D) {
	int ans = -1;
	double best = 0.;
	if(a > 0) {
		double x = D*p10[B-1] + f(a-1, b, c, d);
		if(x >= best) {
			ans = 0;
			best = x;
		}
	}
	if(b > 0) {
		double x = D*p10[B-2] + f(a+1, b-1, c, d);
		if(x >= best) {
			ans = 1;
			best = x;
		}
	}
	if(c > 0) {
		double x = D*p10[d] + (d==B-3 ? f(a, b+1, c-1, 0) : f(a, b, c, d+1));
		if(x >= best) {
			ans = 2;
			best = x;
		}
	}
	return {ans, best};
}

double f(int a, int b, int c, int d) {
	int ind = d + (B-2) * (c + N * (b + N * a));
	if(dp[ind] < 0.) {
		dp[ind] = 0.;
		for(int x = 0; x < 10; ++x) 
			dp[ind] += best_move(a, b, c, d, x).second;
		dp[ind] /= 10.;
	}
	return dp[ind];
}

int main() {

	ll P;
	cin >> T >> N >> B >> P;
	dp.assign(N*N*N*(B-2), -1.);
	for(int i = 1; i < p10.size(); ++i) p10[i] = 10. * p10[i-1];
	const int nSteps = N*B;

	while(T--) {
		int a = 0, b = 0, c = N, d = 0;
		int r = 0;
		for(int s = 0; s < nSteps; ++s) {
			int D;
			cin >> D;
			if(D == -1) return 0;
			auto [ans, best] = best_move(a, b, c, d, D);
			if(ans == 0) {
				ans = r;
				++ r;
				-- a;
			} else if(ans == 1) {
				ans = r + a;
				++ a;
				-- b;
			} else {
				ans = r + a + b;
				if(d == B-3) {
					++ b;
					-- c;
					d = 0;
				} else ++ d;
			}
			cout << ans+1 << endl;
		}
	}

	int good;
	cin >> good;

	return 0;
}