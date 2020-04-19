#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define LL long long
#define VL vector<LL>

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int x = 1; x <= T; x++) {
		int N, L;
		cin >> N >> L;
		VL cipher;
		LL c;
		for(int l = 0; l < L; l++) {
			cin >> c;
			cipher.push_back(c);
		}
		LL p = 2;
		while(cipher[0] % p != 0) p++;
		LL p2 = cipher[0] / p;
		int i = 1;
		while(cipher[i] == cipher[0]) i++;
		VL ps;
		if(cipher[i] % p == 0) {
			for(int j = i; j >= 0; j--)
				ps.push_back(j % 2 == 0 ? p : p2);
		} else {
			for(int j = i; j >= 0; j--)
				ps.push_back(j % 2 == 0 ? p2 : p);
		}
		while(i < L) {
			ps.push_back(cipher[i] / ps[i]);
			i ++;
		}
		set<LL> set_p(ps.begin(), ps.end());
		map<LL, char> letters;
		char add = 0;
		for(LL p : set_p)
			letters[p] = 'A' + (add++);
		cout << "Case #" << x << " ";
		for(LL p : ps)
			cout << letters[p];
		cout << "\n";
	}
	return 0;
}