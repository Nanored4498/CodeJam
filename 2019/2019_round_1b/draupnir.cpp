#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, W;
    cin >> T >> W;
    
    for(int t = 1; t <= T; t++) {
        long long n = 4*(63-7), res;
        cout << n << "\n" << flush;
        cin >> res;
        long long R6 = (res >> (n/6)) & 127;
        long long R5 = (res >> (n/5)) & 127;
        long long R4 = (res >> (n/4)) & 127;
        n = 63-7;
        cout << n << "\n" << flush;
        cin >> res;
        res -= R4 << (n/4);
        long long R3 = (res >> (n/3)) & 127;
        long long R2 = (res >> (n/2)) & 127;
        long long R1 = (res >> (n/1)) & 127;
        cout << R1 << " " << R2 << " " << R3 << " " << R4 << " " << R5 << " " << R6 << "\n" << flush;
        cin >> res;
        if(res == -1) {
			cerr << "Bad answer !" << endl;
			return 1;
		}
    }

    return 0;
}