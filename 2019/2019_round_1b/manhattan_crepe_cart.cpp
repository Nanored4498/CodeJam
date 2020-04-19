#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

using namespace std;

struct People {
	int x, add;
};
bool comp (People &i, People &j) { return i.x < j.x; }

int best(vector<People> &ps) {
	sort(ps.begin(), ps.end(), comp);
	int xb = 0;
	int best = 0;
	for(People &p : ps)
		if(p.add == -1) best ++;
	int num = best;
	int P = ps.size();
	for(int i = 0; i < P; i++) {
		num += ps[i].add;
		if(i+1 < P && ps[i+1].x == ps[i].x) continue;
		if(num > best) xb = ps[i].x, best = num;
	}
	return xb;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int P, Q;
		cin >> P >> Q;
		vector<People> psx, psy;
		int x, y;
		char d;
		for(int i = 0; i < P; i++) {
			cin >> x >> y >> d;
			if(d == 'E') psx.push_back({x+1, 1});
			else if (d == 'W') psx.push_back({x, -1});
			else if(d == 'N') psy.push_back({y+1, 1});
			else if (d == 'S') psy.push_back({y, -1});
		}
		cout << "Case #" << t << ": " << best(psx) << " " << best(psy) << "\n";
	}

	return 0;
}