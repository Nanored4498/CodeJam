#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

vi ans;
bool insert(int i, int offset, int size) {
	int L;
	if(size == 0) {
		ans.insert(ans.begin() + offset, i);
		return true;
	} else if(size == 1) {
		if(offset > 0) {
			cout << ans[offset-1] << " " << ans[offset] << " " << i << endl;
			cin >> L;
			if(L == i) ans.insert(ans.begin() + offset, i);
			else ans.insert(ans.begin() + offset + 1, i);
		} else {
			cout << ans[offset+1] << " " << ans[offset] << " " << i << endl;
			cin >> L;
			if(L == i) ans.insert(ans.begin() + offset + 1, i);
			else ans.insert(ans.begin() + offset, i);
		}
		return L != -1;
	} else {
		int a = (size-2) / 3;
		int r = size-2 - 3*a;
		int b = 2*a + (r == 2 ? 2 : 1);
		cout << ans[offset+a] << " " << ans[offset+b] << " " << i << endl;
		cin >> L;
		if(L == i) return insert(i, offset+a+1, b-a-1);
		else if(L == ans[offset+a]) return insert(i, offset, a);
		else return insert(i, offset+b+1, size-1-b);
	}
}

int main() {
	int T, N, Q;
	cin >> T >> N >> Q;
	for(int t = 1; t <= T; ++t) {
		int L;
		cout << "1 2 3" << endl;
		cin >> L;
		if(L == -1) return 0;
		if(L == 1) ans = {2, 1, 3};
		else if(L == 2) ans = {1, 2, 3};
		else ans = {1, 3, 2};
		for(int i = 4; i <= N; ++i)
			if(!insert(i, 0,  i-1))
				return 0;
		for(int i : ans) cout << i << " ";
		cout << endl;
		cin >> L;
		if(L == -1) return 0;
	}
}