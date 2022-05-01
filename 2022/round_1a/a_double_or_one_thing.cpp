#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		string s, a; cin >> s;
		int i = 0;
		while(i < s.size()) {
			int j = i+1;
			while(j < s.size() && s[j] == s[i]) ++j;
			if(j == s.size() || s[j]<s[i]) a += string(j-i, s[i]);
			else a += string(2*(j-i), s[i]);
			i = j;
		}
		cout << a << '\n';
	}

	return 0;
}