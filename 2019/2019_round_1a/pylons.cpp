#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int R, C;
		cin >> R >> C;
		int size = R*C;
		vector<vector<int>> G(size);
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				if(i%R != j%R && i/R != j/R && (i%R-i/R) != (j%R-j/R) && (i%R+i/R) != (j%R+j/R))
					G[i].push_back(j);
		default_random_engine re;
		for(int i = 0; i < size; i++)
			shuffle(G[i].begin(), G[i].end(), re);
		vector<bool> seen(size, false);
		vector<int> path;
		function<bool(int, int)> dfs = [&](int count, int v) {
			count ++;
			seen[v] = true;
			path.push_back(v);
			if(count == size) return true;
			for(int w : G[v])
				if(!seen[w] && dfs(count, w))
					return true;
			seen[v] = false;
			path.pop_back();
			return false;
		};
		for(int i = 0; i < size; i++)
			if(dfs(0, i))
				break;
		if(path.empty()) {
			cout << "Case #" << t << ": IMPOSSIBLE\n";
		} else {
			cout << "Case #" << t << ": POSSIBLE\n";
			for(int i = 0; i < size; i++)
				cout << path[i] % R + 1 << " " << path[i] / R + 1 << "\n";
		}
	}

	return 0;
}