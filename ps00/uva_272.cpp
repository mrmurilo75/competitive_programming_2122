#include <iostream>
#include <string>

using namespace std;

int main(){
	string line; 
	int flip = -1;
	for(getline(cin, line, '\n'); !cin.eof(); getline(cin, line, '\n') ) {
		for( char &c : line ) {
			if( c == '\"' ) {
				if( (flip *= (-1)) > 0 )
					cout << "``";
				else
					cout << "''";
			} else
				cout << c;
		}
		cout << endl;
	}

}

