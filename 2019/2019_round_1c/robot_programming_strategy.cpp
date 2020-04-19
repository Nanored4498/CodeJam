#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int A;
		cin >> A;
		vector<string> robots;
		set<int> alive;
		string s;
		for(int i = 0; i < A; i++) {
			cin >> s;
			robots.push_back(s);
			alive.insert(i);            
		}
		string res;
		char plays[3] = {'R', 'S', 'P'};
		for(int i = 0; i < A; i++) {
			set<char> c;
			for(int j : alive)
				c.insert(robots[j][i % robots[j].size()]);
			if(c.size() == 3) break;
			int eq = c.size() == 2 ? 0 : 1;
			int val;
			if(c.count('R') == eq) val = 0;
			else if(c.count('S') == eq) val = 1;
			else val = 2;
			res.push_back(plays[(3 + val + 1 - 2*eq) % 3]);
			char cr = plays[(val+2*(1-eq)) % 3];
			vector<int> rem;
			for(int j : alive)
				if(robots[j][i % robots[j].size()] == cr)
					rem.push_back(j);
			for(int j : rem)
				alive.erase(j);
			if(alive.empty()) break;
		}
		cout << "Case #" << t << ": " << (alive.empty() ? res : "IMPOSSIBLE") << "\n";
	}

	return 0;
}