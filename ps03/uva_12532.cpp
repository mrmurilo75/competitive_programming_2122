#include <iostream>
#include <vector>
#include <string>

#define NEUTRAL 1

using namespace std;

vector<int> *value;	// Array of values
vector<int> *st;	// Segtree (in this case storing interval sums)

// Merge contents of nodes a and b
int merge(int a, int b) {
	return a*b;
}

// Build initial segtree (in position pos, interval [start,end])
void build(int pos, int start, int end) {
	if (start == end) {
		(*st)[pos] = (*value)[start]; 	// v[start] is a leaf value
	} else {
		int middle = start + (end-start)/2;
		build(pos*2, start, middle);
		build(pos*2+1, middle+1, end);
		(*st)[pos] = merge((*st)[pos*2], (*st)[pos*2+1]);
	}
	//cout << "st["<<pos<<"] "<<(*st)[pos] <<endl;
}

// Update node x to value r
void update(int pos, int start, int end, int x, int r) {
	if (start>x || end<x) return;
	if (start == end && start == x) {
		(*st)[pos] = r;
	} else {			
		int middle = start + (end-start)/2;
		update(pos*2, start, middle, x, r);
		update(pos*2+1, middle+1, end, x, r);
		(*st)[pos] = merge((*st)[pos*2], (*st)[pos*2+1]);
	}
	//cout << "_st["<<pos<<"] "<<(*st)[pos] <<endl;
}

// Make a query of interval [x,y]
int query(int pos, int start, int end, int x, int y) {
	if (start>y || end<x) return NEUTRAL;
	if (start>=x && end<=y) return (*st)[pos];
	
	int middle = start + (end-start)/2;
	int a = query(pos*2, start, middle, x, y);
	int b = query(pos*2+1, middle+1, end, x, y);
	return merge(a, b);
}

int process_input(int input){ 
	if(input)
		input = ( (input>0)? 1 : -1 );	// input processing
	return input;
}

char process_output(int output){ 
	if(output)
		 return ( (output>0)? '+' : '-' );	// output processing
	return '0';
}

int main() {
	int sizeN, queriesK;
	cin >> sizeN >> queriesK;

	while( cin.good() ) {
		//cout << "n " << sizeN << " k " <<queriesK<<endl;

		value = new vector<int>(sizeN+1);

		st = new vector<int>(4 * (sizeN+1));

			// for (int i=1; i<=n; i++) scanf("%d", &v[i]);
		for(int i =1; i <= sizeN; i++) {
			int input;
			cin >> input;
			input = process_input(input);
			(*value)[i] = input;

			//cout << " in: " << input << endl;
		}

		build(1, 1, sizeN);

		while(queriesK--){
			char qType = '-';
			char nl;
			cin.get(nl);
//			do {
				cin.get(qType);
				//cout << " q: " << (char)qType << " ";
//			} while(qType != 'C' && qType != 'P' && !cin.eof());
			////cout << " q: " << (char)qType <<endl;

			if(qType == 'C'){
				// Change
				int posI, valueV;
				cin >> posI >> valueV;
				//cout << posI << " " << valueV <<endl;
				valueV = process_input(valueV);

				(*value)[posI] = valueV;
				update(1, 1, sizeN, posI, valueV);
			} else {
				// Query 
				int startI, endJ;
				cin >> startI >> endJ;
				//cout << startI << " " << endJ <<endl;

				cout << process_output( query(1, 1, sizeN, startI, endJ) );
			}
		}
		cout << endl;

		char nl;
		cin.get(nl);

		cin >> sizeN >> queriesK;
	}
}

