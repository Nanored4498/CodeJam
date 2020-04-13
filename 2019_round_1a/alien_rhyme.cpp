#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		vector<vector<int>> suff;
		suff.emplace_back(26, -1);
		vector<int> pred = {-1};
		vector<int> count = {0};
		for(int i = 0; i < N; i++) {
			string W ;
			cin >> W;
			int s = 0;
			for(int j = W.size()-1; j >= 0; j--) {
				int c = W[j] - 'A';
				if(suff[s][c] == -1) {
					suff[s][c] = suff.size();
					suff.emplace_back(26, -1);
					pred.push_back(s);
					count.push_back(0);
				}
				s = suff[s][c];
				count[s] ++;
			}
		}
		int res = 0;
		for(int i = suff.size()-1; i >= 0; i--) {
			if(count[i] < 2) continue;
			res += 1;
			int j = i;
			while(j != -1) {
				count[j] -= 2;
				j = pred[j];
			}
		}
		cout << "Case #" << t << ": " << 2*res << "\n";
	}

	return 0;
}