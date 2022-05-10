#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N; cin >> N;
		int count[128], pr[128], nx[128];
		bool seen[128];
		for(char c = 'A'; c <= 'Z'; ++c) seen[c] = count[c] = pr[c] = nx[c] = 0;
		bool bad = false;
		while(N--) {
			string s; cin >> s;
			for(char c : s) ++count[c];
			for(int i = 1; i < s.size(); ++i) if(s[i-1] != s[i]) {
				if(nx[s[i-1]]) bad = true;
				nx[s[i-1]] = s[i];
				if(pr[s[i]]) bad = true;
				pr[s[i]] = s[i-1];
			}
		}
		string ans;
		for(char c = 'A'; c <= 'Z'; ++c) if(!pr[c]) {
			for(char d = c; !seen[d]; d = nx[d]) {
				seen[d] = true;
				ans += string(count[d], d);
			}
		}
		for(char c = 'A'; c <= 'Z'; ++c) if(count[c] && !seen[c]) bad = true;
		if(bad) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}

	return 0;
}