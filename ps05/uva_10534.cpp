#include <iostream>
#include <cstring>
#include <map>

#define ll long long
#define MAX 10009

#define ABOVE 1
#define BELOW 2

#define max(a, b) ((a < b)? b : a)
#define key(a) (*a).first
#define value(a) (*a).second

using namespace std;


int og[MAX], size;
long long result =0, waivo =0;

int main() {

	while(!cin.eof()) {
		cin >> size;
		//cout << size << endl;

		map<int, long long> above, bellow;
		bellow.emplace(0,0);
		above.emplace(0,0);
		bellow.emplace(MAX,0);
		above.emplace(MAX,0);

		for(int i=0; i<size; i++) {
			cin >> og[i];
			//cout << " " << og[i] << "\t";

			auto floor = bellow.lower_bound(og[i]);
			//cout << key(floor) << ", " << value(floor) << endl;
			if( key(floor) == og[i] ) // (*floor).first 
				continue;
			else {
				--floor;
			//cout << key(floor) << ", " << value(floor) << endl;
				bellow.emplace_hint(floor, og[i], value(floor) +1); // (*floor).second
			}
		}
		//cout << endl;
		for(int i=size-1; i>=0; i--) {
			//cout << " " << og[i] << "\t";
			auto ceiling = above.lower_bound(og[i]), hint = ceiling, floor = bellow.lower_bound(og[i]);
			//cout << key(ceiling) << ", " << value(ceiling) << "\t";
			if( key(ceiling) == og[i] )
				continue;
			else {
				--hint;
				//cout << key(hint) << ", " << value(hint);
				above.emplace_hint(hint, og[i], value(ceiling) +1);

				waivo = max(value(ceiling)+1, value(floor));
				result = max(result, waivo);
			}
			//cout << endl;
		}

		cout << result << endl;

	}

}

