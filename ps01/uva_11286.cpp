#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

long generate_key(vector<int> v);

int main(){

    // input
	int i;

	for(cin >> i; i != 0 && !cin.eof(); cin >> i) {
		map<long, int> m;

		while(i--) {
		vector <int> comb(5);

		cin >> comb[0] >> comb[1] >> comb[2] >> comb[3] >> comb[4];

		sort(comb.begin(), comb.end());

		long key = generate_key(comb);

		m[key] ++;

		}

    // process
		int max = 0, tie = 1;
		for(pair<long, int> el : m) {
			if(el.second > max) {
				max = el.second;
				tie = 1;
			} else if(el.second == max) 
				tie++;
		}

    // output
		cout << tie * max << endl;
	}
}

long generate_key(vector<int> v) {
	long res = 0;
	for(int a : v) {
		res <<= 9;
		res += a;
	}
//		cout << res << endl;
	return res;
}


