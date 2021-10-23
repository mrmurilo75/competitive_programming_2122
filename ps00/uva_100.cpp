#include <iostream>

using namespace std;

int cycle_length(int n){
	int counter = 1;

	while(n != 1) {
		if( n%2 == 1 )
			n = 3*n + 1;
		else
			n /= 2;

		counter++;
	}
	return counter;
}

int max(const int a, const int b){
	if(a >= b)
		return a;
	return b;
}

int main(){
	int i, j, sm, xl;
	for( cin >> i >> j; !cin.eof(); cin >> i >> j ) {

		if(i < j) 
			sm = i, xl = j;
		else
			sm = j, xl= i;

		int res = 0;
		for( ; sm <= xl ; sm++ )
			res = max(res, cycle_length(sm));

		cout << i << " " << j << " " << res << endl;
	}

}

