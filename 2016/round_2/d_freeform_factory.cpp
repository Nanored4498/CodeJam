#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int root[50], nr[50], nc[50];
int find(int i) {
	if(root[i] == i) return i;
	return root[i] = find(root[i]);
} 
int nrc(int i) {
	return nr[i] + nc[i];
}
void merge(int i, int j) {
	i = find(i);
	j = find(j);
	if(i == j) return;
	if(nrc(i) < nrc(j)) swap(i, j);
	root[j] = i;
	nr[i] += nr[j];
	nc[i] += nc[j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, ans = 0;
		cin >> N;
		vector<string> M(N);
		for(int i = 0; i < 2*N; ++i) {
			root[i] = i;
			nr[i] = i < N;
			nc[i] = i >= N;
		}
		for(int i = 0; i < N; ++i) {
			cin >> M[i];
			for(int j = 0; j < N; ++j) if(M[i][j] == '1') {
				merge(i, N+j);
				-- ans;
			}
		}

		vector<pair<int, int>> bs;
		for(int i = 0; i < 2*N; ++i) if(find(i) == i)
			bs.emplace_back(nr[i], nc[i]);
		sort(bs.begin(), bs.end());

		vi count, mul;
		int nsubs = N+1;
		for(int i = 0; i < bs.size(); ++i) {
			bs[count.size()] = bs[i];
			count.push_back(2);
			mul.push_back(nsubs);
			while(i+1 < bs.size() && bs[i+1] == bs[i]) {
				++ count.back();
				++ i;
			}
			nsubs *= count.back();
		}
		bs.resize(count.size());

		vi dp(nsubs, N*N), num(bs.size());
		dp[0] = 0;
		for(int st = 0; st < nsubs; ++st) {
			int t = st % (N+1);
			int r = 0, c = 0;
			for(int i = 0; i < bs.size(); ++i) {
				num[i] = (st / mul[i]) % count[i];
				r += num[i] * bs[i].first;
				c += num[i] * bs[i].second;
			}
			for(int i = 0; i < bs.size(); ++i) if(num[i]+1 < count[i]) {
				int st2 = st + mul[i];
				int score = dp[st];
				if(r + bs[i].first == c + bs[i].second) {
					int new_block = r + bs[i].first - t;
					st2 += new_block;
					score += new_block*new_block;
				}
				dp[st2] = min(dp[st2], score);
			}
		}
		ans += dp.back();
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}