#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":\n";
		int R, C;
		cin >> R >> C;
		--R; --C;
		cout << "..+";
		for(int i = 0; i < C; ++i) cout << "-+";
		cout << '\n';
		cout << "..|";
		for(int i = 0; i < C; ++i) cout << ".|";
		cout << '\n';
		cout << "+-+";
		for(int i = 0; i < C; ++i) cout << "-+";
		cout << '\n';
		while(R--) {
			cout << "|.|";
			for(int i = 0; i < C; ++i) cout << ".|";
			cout << '\n';
			cout << "+-+";
			for(int i = 0; i < C; ++i) cout << "-+";
			cout << '\n';
		}
	}

	return 0;
}