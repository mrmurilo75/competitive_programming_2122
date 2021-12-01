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
		//cout <<"\n----------\n"<< sizeN << endl;

		int result =0, waivo =0;

		map<long long, int> above, bellow;
		bellow.emplace(0,0);
		above.emplace(0,0);
		bellow.emplace(LLONG_MAX,0);
		above.emplace(LLONG_MAX,0);

		//cout << "bellow: " << endl;
		for(int i=0; i<sizeN; i++) {
			cin >> og[i];
			//cout << " " << og[i] << "\t";

			auto floor = bellow.lower_bound(og[i]), cur = floor, next = floor;
			--floor;
			count[i][BELLOW] = value(floor)+1;
			if( key(cur) == og[i] ) {
				next++;
				//cout << "e " << key(cur) <<","<< value(cur) <<"\n\t";
				bellow.erase(cur);
			}
			if( value(next) <= count[i][BELLOW] && value(next) ) {
				//cout << "e " << key(next) <<","<< value(next) <<"\n\t";
				bellow.erase(next);
			}
			//cout << key(floor) << ", " << value(floor) << "\t";
			//cout << og[i] << ", " << count[i][BELLOW];
			bellow.emplace_hint(floor, og[i], count[i][BELLOW]); // (*floor).second
			//cout  << endl;
		}
		//cout << endl;
		//cout << "above" << endl;
		for(int i=sizeN-1; i>=0; i--) {
			//cout << " " << og[i] << "\t";

			auto floor = above.lower_bound(og[i]), cur = floor, next = floor;
			--floor;
			count[i][ABOVE] = value(floor)+1;
			if( key(cur) == og[i] ) {
				next++;
				//cout << "e " << key(cur) <<","<< value(cur) <<"\n\t";
				above.erase(cur);
			}
			if( value(next) <= count[i][ABOVE] && value(next) ) {
				//cout << "e " << key(next) <<","<< value(next) <<"\n\t";
				above.erase(next);
			}
			//cout << key(floor) << ", " << value(floor) << "\t";
			//cout << og[i] << ", " << count[i][ABOVE];
			above.emplace_hint(floor, og[i], count[i][ABOVE]); // (*floor).second
			//cout  << endl;
		}

		//cout << "\nres" << endl;
		for(int i=0; i<sizeN; i++) {
			auto ceiling = count[i][ABOVE], floor = count[i][BELLOW];
			//cout << og[i] <<"\t"<< floor <<"\t"<< ceiling << "\t=> ";

			waivo = min(ceiling, floor);
			//cout << waivo << " ==> ";
			// result = max(result, waivo + ((waivo %2)? 0:1) );
			result = max(result, (2* waivo -1) );
			//cout << result << endl;
		}

		cout << result << endl;
	}
	cout << endl;
}

