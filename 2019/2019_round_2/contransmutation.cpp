#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX_M 100001

long long G[MAX_M];
int R[MAX_M][2];
vector<int> iR[MAX_M];
int num[MAX_M], min_num[MAX_M], n;
int stack[MAX_M], ss;
bool in_stack[MAX_M];
vector<vector<int>> C;
int v2C[MAX_M];

void tarjan(int i) {
	num[i] = min_num[i] = n++;
	in_stack[i] = true;
	stack[ss++] = i;
	for(int j : R[i]) {
		if(num[j] == -1) {
			tarjan(j);
			min_num[i] = std::min(min_num[i], min_num[j]);
		} else if(in_stack[j]) min_num[i] = std::min(min_num[i], num[j]);
	}
	if(num[i] == min_num[i]) {
		C.emplace_back();
		int j;
		do {
			j = stack[--ss];
			in_stack[j] = false;
			v2C[j] = C.size()-1;
			C.back().push_back(j);
		} while(j != i);
	}
}

long long rc[MAX_M];
long long dfs(int c) {
	if(rc[c] != -2) return rc[c];
	long long r = 0;
	for(int i : C[c]) {
		r = (r + G[i]) % MOD;
		for(int j : iR[i]) {
			int c2 = v2C[j];
			if(c2 == c) continue;
			long long r2 = dfs(c2);
			if(r2 == -1 || ((v2C[R[j][0]] == c || v2C[R[j][1]] == c) && r2 > 0)) return (rc[c] = -1);
			r = (r + r2) % MOD;
		}
	}
	if(r == 0) return (rc[c] = 0);
	for(int i : C[c]) if(c == v2C[R[i][0]] && c == v2C[R[i][1]]) return (rc[c] = -1);
	return (rc[c] = r);
}

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int M;
		cin >> M;
		for(int i = 1; i <= M; ++i) cin >> R[i][0] >> R[i][1];
		for(int i = 1; i <= M; ++i) cin >> G[i];
		n = ss = 0;
		C.clear();
		for(int i = 0; i <= M; ++i) {
			num[i] = -1;
			in_stack[i] = false;
			iR[i].clear();
			rc[i] = -2;
		}
		for(int i = 1; i <= M; ++i) if(num[i] == -1) tarjan(i);
		for(int i = 1; i <= M; ++i) { iR[R[i][0]].push_back(i); iR[R[i][1]].push_back(i); }
		long long res = dfs(v2C[1]);
		if(res == -1) cout << "Case #" << t << ": UNBOUNDED\n";
		else cout << "Case #" << t << ": " << res << "\n";
	}

	return 0;
}