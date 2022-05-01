#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
typedef vector<int> vi;
const int D = 8;
const int MT = 30;

int cnz(int i) {
	int ans = 0;
	for(int j = 0; j < D; ++j) if((i>>j)&1) ++ans;
	return ans;
}

int main() {
	vi vals, can(1<<D);
	for(int i = 0; i < (1<<D); ++i) {
		can[i] = i;
		for(int k = D, j = i; --k;) {
			j = (j>>1)|((j&1)<<(D-1));
			can[i] = min(can[i], j);
		}
		if(can[i] == i) vals.push_back(i);
	}
	vector<vi> nv(D+1);
	vi ind(1<<D, -1);
	for(int i : vals) { ind[i] = nv[cnz(i)].size(); nv[cnz(i)].push_back(i); }
	for(int i = 0; i < (1<<D); ++i) if(ind[i] == -1) ind[i] = ind[can[i]];
	for(const vi &v : nv) cerr << v.size() << ' '; cerr << endl;
	int ms = 0; for(const vi &v : nv) ms = max(ms, (int) v.size());
	vector<vector<vi>> nxt(1<<D, vector<vi>(1<<D, vi(D+1, 0))), nxtp((D+1)<<ms, vector<vi>(1<<D, vi(D+1, 0)));
	for(int i : vals) for(int j : vals) {
		for(int k = D, j0=j; k--;) {
			j = (j>>1)|((j&1)<<(D-1));
			int n = i^j;
			nxt[i][j0][cnz(n)] |= 1<<ind[n];
		}
	}
	for(int n = 0; n <= D; ++n) {
		const int ns = nv[n].size();
		for(int p = 1; p < (1<<ns); ++p)
			for(int j : vals)
				for(int i = 0; i < ns; ++i) if((p>>i)&1)
					for(int k = 0; k <= D; ++k)
						nxtp[(n<<ms)|p][j][k] |= nxt[j][nv[n][i]][k];
	}
	const int INF = 1e9;
	vector<int> succ((D+1)<<ms, 0), dist((D+1)<<ms, INF);
	for(int n = 0; n <= D; ++n) dist[n<<ms] = 0;
	dist[1] = 0;
	for(int step = 0; step < MT; ++step) {
		for(int n = 0; n <= D; ++n) {
			const int ns = nv[n].size();
			for(int p = 1; p < (1<<ns); ++p) if(dist[(n<<ms)|p]) {
				for(int j : vals) {
					int d = 0;
					for(int k = 0; k <= D; ++k) d = max(d, dist[(k<<ms)|nxtp[(n<<ms)|p][j][k]]);
					++ d;
					if(d < dist[(n<<ms)|p]) {
						dist[(n<<ms)|p] = d;
						succ[(n<<ms)|p] = j;
					}
				}
			}
		}
	}
	for(int n = 0; n <= D; ++n) cerr << "Dist: " << dist[(n<<ms)|((1<<nv[n].size())-1)] << ' ' << succ[(n<<ms)|((1<<nv[n].size())-1)] << endl;

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << bitset<D>(0) << endl;
		int N; cin >> N;
		int p = (1<<nv[N].size())-1;
		while(N) {
			const int j = succ[(N<<ms)|p];
			cout << bitset<D>(j) << endl;
			int M; cin >> M; if(M == -1) return 1;
			p = nxtp[(N<<ms)|p][j][M];
			N = M;
		}
	}
	return 0;
}