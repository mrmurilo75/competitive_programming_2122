#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct FenwickTree { // Fenwick Tree based on https://cp-algorithms.com/data_structures/fenwick.html#toc-tgt-9
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0 && idx < n; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    
    void print() {
	for( int i : bit ) cout << " " << i;
	cout << endl;
    }
};  // */

long long connections(FenwickTree **connects, const int c_size, int e, int w) {
	long long result = 0;
	if(e < c_size-1) 
		for(int upE = e+1; upE < c_size; upE++) {
			result += connects[upE]->sum(0, w-1);
		}

	if(e > 0)
		for(int downE = e-1; downE >= 0; downE--) {
			result += connects[downE]->sum(w+1, c_size);
		}

	return result; 
}

int main(){
	int casesT;
	cin >> casesT;
	//cout << "casesT " << casesT << endl;

	for(int i=1; i <= casesT; i++){
		int eastN, westM, waysK, result = 0;
		cin >> eastN >> westM >> waysK;
		//cout <<"N "<< eastN <<"\tM "<< westM <<"\tK "<< waysK << endl;

		FenwickTree **connects = (FenwickTree**) malloc(eastN * sizeof(FenwickTree*));
		for(int i=0; i < eastN; i++) {
			connects[i] = new FenwickTree(westM);
//			connects[i]->print();
		}

		for(int i=0, e, w; i < waysK; i++) {
			cin >> e >> w;
			e--, w--;
			//cout <<"e "<< e <<"\tw "<< w <<endl;

			connects[e]->add(w, 1);
//			connects[e]->print();
			result += connections(connects, eastN, e, w);

			//cout << "r " << result << endl;
		}

		cout << "Test case "<< i <<": " << result << endl;

	}

}

