#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int generate_key(vector<int> v);

int main(){
	int i;
	for(cin >> i; i != 0 && !cin.eof(); cin >> i) {

		map<int, int> m;

		while(i--) {
		vector <int> comb(5);
		cin >> comb[0] >> comb[1] >> comb[2] >> comb[3] >> comb[4];
		sort(comb.begin(), comb.end());
		int key = generate_key(comb);

		if(m.find(key) == m.end())
			m[key] = 1;
		else
			m[key] ++;
		}
	}
}

