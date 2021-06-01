#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
struct Point {
	T x, y;
	Point()=default;
	Point(T x, T y): x(x), y(y) {}

	Point operator+(const Point &p) { return {x+p.x, y+p.y}; }
	Point operator-(const Point &p) { return {x-p.x, y-p.y}; }
	friend Point operator*(T a, const Point &p) { return {a*p.x, a*p.y}; }
	Point operator/(T a) { return {x/a, y/a}; }
	Point& operator*=(T a) { x *= a; y *= a; return *this; }
	Point& operator/=(T a) { x /= a; y /= a; return *this; }
	friend istream& operator>>(istream &in, Point &p) { return in >> p.x >> p.y; }

	friend Point turn90(const Point &p) { return {-p.y, p.x}; }
	friend T dot(const Point &a, const Point &b) { return a.x*b.x + a.y*b.y; }
};

typedef Point<int> pt;
const int MN = 202;

pt pts[2*MN];

void print(int n, int d) {
	int g = __gcd(n, d);
	n /= g;
	d /= g;
	cout << n << '/' << d;
}

void print(const pt &p, int d) {
	print(p.x, d);
	cout << ' ';
	print(p.y, d);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N, K;
		cin >> N >> K;
		for(int i = 0; i < N; ++i) {
			cin >> pts[2*i];
			pts[2*i] *= 2;
		}
		for(int i = 0; i+1 < N; ++i) pts[2*i+1] = (pts[2*i] + pts[2*i+2]) / 2;
		pts[2*N-1] = (pts[2*N-2] + pts[0]) / 2;
		bool good;
		for(int i = 0; i < 2*N; ++i) {
			int j = (i + N) % (2*N);
			Point vec = pts[j] - pts[i];
			Point orth = turn90(vec);
			good = true;
			for(int k = 1; k < N; ++k) {
				Point p1 = pts[(i+k)%(2*N)] - pts[i];
				Point p2 = pts[(i+2*N-k)%(2*N)] - pts[i];
				int x1 = dot(vec, p1), y1 = dot(orth, p1);
				int x2 = dot(vec, p2), y2 = dot(orth, p2);
				if(x1 != x2 || y1 <= 0 || y2 != -y1) {
					good = false;
					break;
				}
			}
			if(good) {
				cout << "POSSIBLE\n";
				print(pts[i], 2);
				cout << ' ';
				print(pts[j], 2);
				cout << '\n';
				break;
			}
		}
		if(!good) cout << "IMPOSSIBLE\n";
	}

	return 0;
}