#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<int> F(N);
		for(int i = 0; i < N; ++i) {
			cin >> F[i];
			-- F[i];
		}
		vector<int> l2(N, 0);
		int ans = 0;
		for(int i = 0; i < N; ++i) {
			vector<int> ind(N, -1);
			ind[i] = 0;
			int j = i;
			while(ind[F[j]] == -1) {
				ind[F[j]] = ind[j]+1;
				j = F[j];
			}
			int L = ind[j];
			int loop = L + 1 - ind[F[j]];
			if(loop > 2) ans = max(ans, loop);
			else {
				j = F[j];
				l2[j] = max(l2[j], L);
			}
		}
		int sl2 = 0;
		for(int l : l2) sl2 += l;
		ans = max(ans, sl2);
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}