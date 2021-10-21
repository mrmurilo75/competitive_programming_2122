#include <iostream>

using namespace std;

int main(){
	long long q, a, b, k;
	cin >> q;
	while(q--){
		cin >> a >> b >> k;

		a *= k/2 + k%2;
		b *= k/2;

		cout << a-b << endl;
	}

}

