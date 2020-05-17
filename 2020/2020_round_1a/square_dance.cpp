#include <iostream>
#include <vector>

using namespace std;

struct Competitor {
	long long S;
	int compas[4];
	long long time;
};

int T, R, C, s;
Competitor competitors[100000];

int diff(int k) {
	const Competitor &c = competitors[k];
	int res = 0;
	for(int i = 0; i < 4; ++i)
		if(c.compas[i] != -1)
			res += c.S - competitors[c.compas[i]].S;
	return res;
}

void update_dir(int i, int dir) {
	int j = competitors[i].compas[dir];
	if(j == -1 || competitors[j].time == 0) return;
	update_dir(j, dir);
	competitors[i].compas[dir] = competitors[j].compas[dir];
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> R >> C;
		int ind = 0;
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				cin >> s;
				competitors[ind] = {
					s,
					{
						r == 0 ? -1 : ind-C,
						r == R-1 ? -1 : ind+C,
						c == 0 ? -1 : ind-1,
						c == C-1 ? -1 : ind+1
					},
					0
				};
				++ ind;
			}
		}
		int size = R*C;
		vector<int> to_update, next_update;
		long long time = 1;
		for(int i = 0; i < size; ++i)
			if(diff(i) < 0) {
				competitors[i].time = time;
				to_update.push_back(i);
			}
		while(!to_update.empty()) {
			for(int i : to_update) {
				for(int j = 0; j < 4; ++j) {
					update_dir(i, j);
					int k = competitors[i].compas[j];
					if(k != -1) update_dir(k, j^1);
				}
			}
			++ time;
			next_update.clear();
			for(int i : to_update) {
				for(int j = 0; j < 4; ++j) {
					int k = competitors[i].compas[j];
					if(k != -1 && competitors[k].time == 0 && diff(k) < 0) {
						competitors[k].time = time;
						next_update.push_back(k);
					}
				}
			}
			swap(to_update, next_update);
		}
		long long res = 0;
		for(int i = 0; i < size; ++i)
			res += competitors[i].S * (competitors[i].time == 0 ? time : competitors[i].time);
		std::cout << "Case #" << t << ": " << res << "\n";
	}

	return 0;
}