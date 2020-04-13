#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int day;
		for(int i = 0; i < 99; i++) {
			cin >> day;
			cout << 2+(i%19) << " " << 100 - i/19 << endl;
		}
		cout << 1 << " " << 100 << endl;
	}

	return 0;
}