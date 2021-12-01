#include <iostream>
#include <cstring>
#include <map>
#include <limits.h>

#define MAX 10009

#define ABOVE 0
#define BELLOW 1

#define max(a, b) ((a < b)? b : a)
#define min(a, b) ((a < b)? a : b)
#define key(a) (*a).first
#define value(a) (*a).second

using namespace std;


long long og[MAX];
int sizeN, count[MAX][2];

int main() {

	for(cin >> sizeN; !cin.eof(); cin >> sizeN) {

		int result =0, waivo =0;

		map<long long, int> above, bellow;
		bellow.emplace(0,0);
		above.emplace(0,0);
		bellow.emplace(LLONG_MAX,0);
		above.emplace(LLONG_MAX,0);

		for(int i=0; i<sizeN; i++) {
			cin >> og[i];

			auto floor = bellow.lower_bound(og[i]), cur = floor, next = floor;
			--floor; // get actual floor

			count[i][BELLOW] = value(floor)+1; // cur count value

			if( key(cur) == og[i] ) { // remove key if exists bc of stdlib bug
				next++;
				bellow.erase(cur);
			}

			if( value(next) <= count[i][BELLOW] && value(next) ) { // if next has bigger key but count is the sameor less --> rm bc we would never use it
				bellow.erase(next);
			}

			bellow.emplace_hint(floor, og[i], count[i][BELLOW]); 
		}

		for(int i=sizeN-1; i>=0; i--) { // same as for bellow, but going from last to first

			auto floor = above.lower_bound(og[i]), cur = floor, next = floor;
			--floor;
			count[i][ABOVE] = value(floor)+1;
			if( key(cur) == og[i] ) {
				next++;
				above.erase(cur);
			}
			if( value(next) <= count[i][ABOVE] && value(next) ) {
				above.erase(next);
			}
			above.emplace_hint(floor, og[i], count[i][ABOVE]); 
		}

		for(int i=0; i<sizeN; i++) { // get maximum waivo from results
			auto ceiling = count[i][ABOVE], floor = count[i][BELLOW];

			waivo = min(ceiling, floor);
			result = max(result, (2* waivo -1) );
		}

		cout << result << endl;
	}
	cout << endl;
}

