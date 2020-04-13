#include <iostream>
#include <vector>

using namespace std;

bool seen[100];
int pred[100];
vector<int> G[100];

bool f(int u) {
	for(int v : G[u]) {
		if(!seen[v]) {
			seen[v] = true;
			if(pred[v] == -1 || f(pred[v])) {
				pred[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		int a;
		vector<int> M[2*N+1];
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++) {
				cin >> a;
				M[a+N].push_back(i+j*N);
			}
		int res = N*N;
		for(int i = 0; i <= 2*N; i++) {
			if(i == N) continue;
			for(int j = 0; j < N; j++)
				pred[j] = -1, G[j].clear();
			for(int j : M[i]) G[j%N].push_back(j/N);
			for(int u = 0; u < N; u++) {
				for(int j = 0; j < N; j++) seen[j] = false;
				if(f(u)) res --;
			}
		}
		cout << "Case #" << t << ": " << res << "\n";
	}

	return 0;
}