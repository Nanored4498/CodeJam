#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MOD 1000000007

vector<int> R1, R2;
vector<long long> G;
vector<vector<int>> pred;
vector<bool> seen;

void g(int i) {
	if(G[i] == -1) return;
	G[i] = -1;
	g(R1[i]);
	g(R2[i]);
}

long long f(int i) {
	if(seen[i]) return G[i];
	long long pred = G[i];
	G[R1[i]] += G[i];
	G[R2[i]] += G[i];
	seen[i] = true;
	for(int p : pred[i]) {
		long long r = f(p);
		if(r < 0)
		G[i] = (G[i] + r) % MOD;
	}
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int M;
		cin >> M;
		R1.clear();
		R2.clear();
		G.clear();
		pred.clear();
		seen.clear();
		for(int i = 0; i < M; i++)
			seen.push_back(false), pred.push_back({});
		long long a, b;
		for(int i = 0; i < M; i++) {
			cin >> a >> b;
			a--, b--;
			R1.push_back(a);
			R2.push_back(b);
			pred[a].push_back(i);
			pred[b].push_back(i);
		}
		for(int i = 0; i < M; i++) {
			cin >> a;
			G.push_back(a);
		}
	}

	return 0;
}