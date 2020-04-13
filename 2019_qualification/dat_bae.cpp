#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T --> 0) {
		int N, B, F;
		cin >> N >> B >> F;
		vector<int> err;
		int n = 0;
		char b = '0';
		while(n < N) {
			int l = min(16, N-n);
			for(int i = 0; i < l; i++) cout << b;
			n += l;
			err.push_back(l);
			b = b == '0' ? '1' : '0';
		}
		cout << endl;
		string ans;
		cin >> ans;
		cerr << ans;
	}
	return 0;
}