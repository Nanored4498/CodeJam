#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;

int T, N, C;
vector<vi> w;
vector<vb> e;

void getXKL(int t, int &x, int &k, int &l) {
	x = 0;
	for(int i = 0; i < N; ++i) {
		if(e[t][i]) ++ x;
		else {
			k = l;
			l = i;
		}
	}
}

int main() {
	cin >> T >> N >> C;

	w.resize(T, vi(N));
	e.resize(T, vb(N));

	vector<vector<vd>> dp(N-1);
	vector<vector<vb>> n(N-1);
	for(int x = N-2; x >= 0; --x) {
		dp[x].resize(x+2);
		n[x].resize(x+2);
		for(int a = 0; a <= x+1; ++a) {
			dp[x][a].resize(a+1);
			n[x][a].resize(a+1);
			for(int b = 0; b <= a; ++b) {
				double good = 0, num = ((N-x-1)*(N-x)) / 2;
				int mid = max(x, (N + a + b - 1) / 2 + 1);
				if(mid < N-1) good += ((N-1-mid)*(N-mid)) / 2;
				int n0 = max(0, x - a - b), n1 = max(0, mid - a - b);
				good += (n1*(n1-1) - n0*(n0-1)) / 2;
				double p0 = good / num;
				double p1 = x == N-2 ? 0. : ((N-x-2) * dp[x+1][a][b] + dp[x+1][x+1][b] + dp[x+1][x+1][x+1]) / (N-x);
				if(p0 >= p1) {
					dp[x][a][b] = p0;
					n[x][a][b] = false;
				} else {
					dp[x][a][b] = p1;
					n[x][a][b] = true;
				}
			}
		}
	}
	cerr << dp[0][0][0] << " vs " << double(C) / double(T) << endl;
	
	bool finish = false;
	while(true) {
		bool finish = true;
		vi idx(T);
		for(int t = 0; t < T; ++ t) {
			int x, k, l;
			getXKL(t, x, k, l);
			int a = w[t][k], b = w[t][l];
			idx[t] = 0;
			if(n[x][a][b]) {
				finish = false;
				while(e[t][idx[t]] || w[t][idx[t]] == x+1) ++ idx[t];
				++ idx[t];
			}
			cout << idx[t] << ' ';
		}
		cout << endl;
		if(finish) break;
		for(int t = 0; t < T; ++ t) {
			int b;
			cin >> b;
			if(idx[t] > 0) {
				-- idx[t];
				if(b == 1) ++ w[t][idx[t]];
				else e[t][idx[t]] = true;
			}
		}
	}

	for(int t = 0; t < T; ++t) {
		int x, k, l;
		getXKL(t, x, k, l);
		cout << k+1 << ' ' << l+1 << ' ';
	}
	cout << endl;

	return 0;
}