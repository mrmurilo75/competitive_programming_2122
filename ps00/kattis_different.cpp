#include <iostream>

using namespace std;

int main(){
	long a, b;
	cin >> a >> b;
	while(!cin.eof()){
		cout << abs(a - b) << endl;
		cin >> a >> b;
	}
}

