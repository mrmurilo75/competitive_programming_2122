#include <iostream>

using namespace std;

int r(int i){
	int r = 0;
	while(i != 0){
		int c = i%10;
		i /= 10;
		r = r*10 + c;
	}
	return r;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int a, b;
		cin >> a; cin >> b;

		cout << r( r(a) + r(b) ) << "\n";
	}
}

