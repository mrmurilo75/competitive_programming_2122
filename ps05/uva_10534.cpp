#include <iostream>
#include <cstring>
#include <list>

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

list<int> above, bellow;

int main() {

	for(cin >> sizeN; cin.good(); cin >> sizeN) {
		//cout << "n " << sizeN <<endl;

		int result =0, waivo =0, i;

//		memset(indexI, -1, sizeof indexI);

		above.clear();
		above.emplace_front(0);
			count[0][ABOVE] = 1;
		bellow.clear();
		bellow.emplace_front(sizeN-1);
			count[sizeN-1][BELLOW] = 1;

		for(i = 0; i < sizeN; i++) {
			cin >> og[i];
			//cout << i <<" - "<< og[i] << endl;
		}

		//cout << endl;
		//cout <<"ABOVE"<< endl;
		for(i = 1; i < sizeN; i++) {
			//cout << i <<" - "<< og[i] << endl;

			count[i][ABOVE] = 1;

			auto j = above.begin();
			for(; j != above.end(); ++j) {
				//cout <<"\t"<< *j <<" - "<< og[*j] << endl;

				if( og[ *j ] < og[i] ) {
					count[i][ABOVE] = count[ *j ][ABOVE] +1;
					break;
				}
			}
			//cout << "\t\t" << count[i][ABOVE];

			if( j == above.end() ) {
				//cout << i << " <- ";
				above.emplace_back(i);
				continue;
			}
			if( og[ *j ] < og[i] ) {
				//cout << *j << " <- ";
				j = above.emplace(j, i);
				//cout << *j << endl;

			}else if( count[i][ABOVE] >= count[ *j ][ABOVE]) {
				//cout << *j << " r  " ;
				j = above.emplace(j, i);
				//cout << *j << endl;
				++j;
				above.erase(j);

			}
			//cout << endl;
		}

		//cout << "BELLOW" << endl;
		for(i=sizeN-2; i>=0; i--) { // same as for bellow, but going from last to first
			//cout << i <<" ";

			count[i][BELLOW] = 1;

			auto j = bellow.begin();
			for(; j != bellow.end(); ++j) {
				//cout <<"\t"<< *j <<" - "<< og[*j] << endl;

				if( og[ *j ] < og[i] ) {
					count[i][BELLOW] = count[ *j ][BELLOW] +1;
					break;
				}
			}
			//cout << "\t\t" << count[i][BELLOW];

			if( j == bellow.end() ) {
				//cout << i << " <- ";
				bellow.emplace_back(i);
				continue;
			}
			if( og[ *j ] < og[i] ) {
				//cout << *j << " <- ";
				j = bellow.emplace(j, i);
				//cout << *j << endl;

			}else if( count[i][BELLOW] >= count[ *j ][BELLOW]) {
				//cout << *j << " r  " ;
				j = bellow.emplace(j, i);
				//cout << *j << endl;
				++j;
				bellow.erase(j);

			}
			//cout << endl;
		}

		//cout << "result" <<endl;
		for(int i=0; i<sizeN; i++) { // get maximum waivo from results
			auto ceiling = count[i][ABOVE], floor = count[i][BELLOW];
			//cout << i <<"\t"<< ceiling <<"\t"<< floor <<"\t";

			waivo = min(ceiling, floor);
			result = max(result, (2* waivo -1) );
			//cout <<"= "<< result <<endl;
		}

		cout << result << endl;
	}
}

