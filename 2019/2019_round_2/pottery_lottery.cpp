#include <iostream>
#include <vector>

using namespace std;

#define NV 20
#define NP 100
#define STEP1 60
#define STEP2 87
#define V1 10
#define V2 7

int main() {
	int T, N, day, p;
	cin >> T;
	bool in[NV+1][NP+1];
	double score[NV+1];

	for(int t = 1; t <= T; t++) {
		for(int v = 1; v <= NV; ++v)
			for(int p = 1; p <= NP; ++p)
				in[v][p] = false;
		do {
			cin >> day;
			cout << 1+(day % V1) << " " << (day <= V1 ? NP : day) << endl;
		} while(day < STEP1);
		do {
			cin >> day;
			int v = day-STEP1+V1;
			cout << v << " 0" << endl;
			cin >> N;
			score[v] = N + (STEP1+V2-day) / 20.;
			for(int i = 0; i < N; ++i) {
				cin >> p;
				if(p > STEP1+1) for(int w = V1+1; w < p-STEP1+V1; ++w) score[w] -= 1./20.;
				in[v][p] = true;
			}
		} while(day < STEP1+V2);
		int chosen = V1+1;
		for(int v = V1+2; v <= V1+V2; ++v)
			if(score[v] < score[chosen]) chosen = v;
		do {
			cin >> day;
			int to = chosen == V1+1 ? V1+2 : V1+1;
			for(int v = V1+1; v <= V1+V2; ++v)
				if(v != chosen && score[v] < score[to]) to = v;
			int add = in[to][NP] ? 1 : NP;
			while(in[to][add]) ++add;
			in[to][add] = true;
			score[to] += 1.;
			cout << to << " " << add << endl;
		} while(day < STEP2);
		for(int v = V1+1; v <= V1+V2; ++v) score[v] += (STEP2+NV-(V1+V2)+1 - (STEP1+V2))/20.;
		do {
			cin >> day;
			int v = day - STEP2 + V1+V2;
			if(v > NV) v = chosen;
			cout << v << " 0" << endl;
			cin >> N;
			score[v] = N + (STEP2 + NV-(V1+V2)+1-day) / 20.;
			for(int i = 0; i < N; ++i) {
				cin >> p;
				if(p > STEP1+1) for(int w = V1+1; w < p-STEP1+V1 && w <= V1+V2; ++w) score[w] -= 1./20.;
				if(p > STEP2+1) for(int w = V1+V2+1; w < p-STEP2+V1+V2; ++w) score[w] -= 1./20.;
				in[v][p] = true;
			}
		} while(day < STEP2 + NV-(V1+V2)+1);
		for(int v = V1+V2+1; v <= NV; ++v)
			if(score[v] < score[chosen]) chosen = v;
		do {
			cin >> day;
			int to = chosen == V1+1 ? V1+2 : V1+1;
			for(int v = V1+1; v <= NV; ++v)
				if(v != chosen && score[v] < score[to]) to = v;
			int add = in[to][NP] ? 1 : NP;
			while(in[to][add]) ++add;
			in[to][add] = true;
			score[to] += 1.;
			cout << to << " " << add << endl;
		} while(day < 99);
		cin >> day;
		cout << chosen << " " << NP << endl;
	}

	return 0;
}