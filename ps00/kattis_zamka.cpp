#include <iostream>

using namespace std;

int add_digits(int a) {
	int res = 0;
	while(a != 0) {
		res += a%10;
		a /= 10;
	}
	return res;
}

int main(){
	//brute force
	int l, d, x;
	cin >> l; cin >> d; cin >> x;

	// brute force
	while(add_digits(l) != x)
		l++;
	while(add_digits(d) != x)
		d--;

	cout << l << "\n" << d << "\n";
}

