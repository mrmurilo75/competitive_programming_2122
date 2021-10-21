#include <iostream>

using namespace std;

int main(){
	int i, j;
	cin >> i >> j;

	while(!cin.eof()) {
		int m = 0, r = 0;
		while(i-- >= j)
			( (m = max_cycle_length(i)) > r )? r = m : 0;

		cout << r;
	}


}

