#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct route {
	int east, west;
};

int bit[1009];

long long sum(int pos) {
	long long result = 0;

	while(pos) {
		result += bit[pos];
		pos -= (pos & -pos);
	}

	return result;
}

void increase(int pos, int bound) {
	while(pos <= bound) {
		bit[pos]+=1;
		pos += (pos & -pos);
	}
}

bool compare(const route &a ,const route &b) {
	return a.east == b.east ? a.west < b.west : a.east < b.east;
}

int main() {
	int t;
	scanf("%d", &t);

	for(int l = 1; l <= t; l++) {
		int n, m, k, a, b;
		scanf("%d%d%d", &n, &m, &k);

		route ways[1000009];
		memset(bit,0,sizeof bit);

		for(int i = 0; i < k; i++) {
			scanf("%d%d", &a, &b);

			ways[i].east = a;
			ways[i].west = b;
		}

		sort(ways,ways+k,compare);

		long long result = 0;
		for(int i = 0; i < k; i++) {
			result += (sum(m) - sum(ways[i].west));
			increase(ways[i].west , m);
		}

		cout << "Test case " << l << ": " << result << endl;
	}
}

